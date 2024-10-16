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
        printf("Stack overflow!");
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
        printf("Stack is Empty!");
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
        printf("Stack is Empty!");

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
        printf("Stack is Empty!");

    int i = 1, x = -1;
    struct Node *p = top;

    for(;i<n && p!=NULL;i++)
    {
        p = p->next;
        x = p->data;
    }

    return i==n?x:-1;
}

int CheckBalencedOrNot(struct Node **top, char exp[])
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(')
        {
            Push(&(*top), exp[i]);
        }
        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')')
        {
            char temp = Pop(&(*top));
            if(exp[i] - temp == 2 || exp[i] - temp ==1)
                continue;
            else
                return 0;
        }
    }
    return *top==NULL?1:0;
}

int main()
{
    struct Node *top = NULL;
    char exp[] = "{([a+b]*[c-d])/e}";
    printf("%d",CheckBalencedOrNot(&top, exp));
}



