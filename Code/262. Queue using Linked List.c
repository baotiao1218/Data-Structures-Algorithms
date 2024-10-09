#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void Enqueue(struct Node **front, struct Node **rear, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;
    t->next = NULL;
    if (*front == NULL)
        *front = *rear = t;
    else
    {
        (*rear)->next = t;
        *rear = t;
    }
}

int Dequeue(struct Node **front)
{
    struct Node *p = *front;
    int x = -1;

    if(*front != NULL)
    {
        x = (*front)->data;
        *front = (*front)->next;
        free(p);
    }

    return x;
}

void Display(struct Node *front)
{
    struct Node *p = front;
    while(p != NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
}

int main()
{
    struct Node *front = NULL,*rear = NULL;

    Enqueue(&front,&rear, 1);
    Enqueue(&front,&rear, 2);
    Enqueue(&front,&rear, 3);
    Enqueue(&front,&rear, 4);
    Enqueue(&front,&rear, 5);
    printf("%d \n",Dequeue(&front));

    Display(front);

    return 0;
}
