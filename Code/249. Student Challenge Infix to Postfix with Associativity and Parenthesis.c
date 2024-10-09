//************失敗***************

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
};

void Push(struct Node **top, char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if(!temp)
        printf("Stack overflow!\n");
    else
    {
        temp->data = x;
        temp->next = *top;
        *top = temp;
    }
}

char Pop(struct Node **top)
{
    char x = NULL;
    if(*top==NULL)
        printf("Stack is Empty!(Pop)\n");
    else
    {
        struct Node *p = *top;
        x = p->data;
        *top = (*top)->next;
        free(p);
    }
    return x;
}

char StackTop(struct Node *top)
{
    return top!=NULL?(top->data):-1;
}

void Display(struct Node *top)
{
    if(top==NULL)
        printf("Stack is Empty!\n");

    int pos = 0;
    struct Node *p = top;

    while(p!=NULL)
    {
        pos++;
        printf("Pos: %c, Value: %c\n", pos, p->data);
        p = p->next;
    }
}

char Peek(struct Node *top, int n)
{
    if(top==NULL)
        printf("Stack is Empty!\n");

    int i = 1, x = -1;
    struct Node *p = top;

    for(;i<n && p!=NULL;i++)
    {
        p = p->next;
        x = p->data;
    }

    return i==n?x:-1;
}

int IsOperand(char c)
 {
    return (c >= 'a' && c <= 'z');
 }

int OutPre(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if((c == '*' || c == '/'))
        return 3;
    else if(c == '^')
        return 6;
    else if(c == '(')
        return 7;
    else if(c == ')')
        return 0;
    else
        return -1;
}

int InPre(char c)
{
    if(c == '+' || c == '-')
        return 2;
    else if((c == '*' || c == '/'))
        return 4;
    else if(c == '^')
        return 5;
    else if(c == '(')
        return 0;
    else
        return -1;
}

char *ConverterwPare(char *infix)
{
    struct Node *st = NULL;
    char *postfix = (char *)malloc(strlen(infix)+1);

    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        //printf("%c",infix[i]);
        if(IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            //printf("%d, %d \n",OutPre(infix[i]),InPre(StackTop(st)));
            if(OutPre(infix[i]) > InPre(StackTop(st)))
                if(infix[i] == ')')
                    i++;
                else
                    Push(&st, infix[i++]);
            else
                if(StackTop(st) == '(')
                   Pop(&st);
                else
                    postfix[j++] = Pop(&st);
        }
    }

    while(st != NULL)
    {
        postfix[j++] = Pop(&st);
    }

    postfix[j] = '\0';

    return postfix;
}
int main()
{
    char exp[] = "((a+b)*c)-d^e^f";
    char *postfix = ConverterwPare(exp);
    //printf("\n%s", postfix);
    printf("%s", postfix);
}

