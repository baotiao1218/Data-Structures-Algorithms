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
        printf("Stack is Empty!\n");
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
    if(c >= '0' && c <= '9')
       return 0;
    else
       return 1;
 }

int Pre(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if((c == '*' || c == '/'))
        return 2;
    else
        return -1;
}

char *Converter(char *infix)
{
    struct Node *st = NULL;

    char *postfix = (char *)malloc(strlen(infix)+1);
    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        if(IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(Pre(infix[i]) > Pre(StackTop(st)))
                Push(&st,infix[i++]);
            else
                postfix[j++] = Pop(&st);
        }
    }

    while(st!=NULL)
        postfix[j++] = Pop(&st);

    postfix[j] = '\0';

    return postfix;
}
int main()
{
    struct Node *top = NULL;
    char exp[] = "a+b*c-d/e";
    char *postfix = Converter(exp);
    printf("%s", postfix);
}

