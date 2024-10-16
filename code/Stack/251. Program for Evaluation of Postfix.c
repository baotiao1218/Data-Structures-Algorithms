#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int Push(struct Node **top, char x)
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

int Pop(struct Node **top)
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

int StackTop(struct Node *top)
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

int IsNum(char c)
{
return (c >= '0' && c <= '9');
}

int EvaluatePostfix(char *postfix)
{
    int r, x, y, answer = -1;
    struct Node *st = NULL;

    for(int i = 0; postfix[i] != '\0'; i++)
    {
        if(IsNum(postfix[i]))
            Push(&st, postfix[i]-48);
        else
        {
            y = Pop(&st);
            x = Pop(&st);
            //printf("%d, %d\n",x,y);
            switch(postfix[i])
            {
                case '+':
                    r = x + y;
                    break;
                case '-':
                    r = x - y;
                    break;
                case '*':
                    r = x * y;
                    break;
                case '/':
                    r = x / y;
                    break;
            }
            Push(&st, r);
        }
    }
    answer = Pop(&st);
    return answer;
}


int main()
{
    char exp[] = "35*62/+4-";
    int answer = EvaluatePostfix(exp);
    printf("%d", answer);
}
