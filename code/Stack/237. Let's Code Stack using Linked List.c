#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void Push(struct Node **top, int x)
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

int Pop(struct Node **top)
{
    int x = -1;
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

int StackTop(struct Node *top)
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
        printf("Pos: %d, Value: %d\n", pos, p->data);
        p = p->next;
    }
}

int Peek(struct Node *top, int n)
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

int main()
{
    struct Node *top = NULL;

    Push(&top, 35);
    Push(&top, 45);
    Push(&top, 55);

    printf("%d\n",StackTop(top));
    Display(top);

    return 0;
}



