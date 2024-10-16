#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Enqueue(struct Queue *q, int x)
{
    if(q->rear == (q->size -1))
        printf("Queue is full.");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
        //q->size[++(q->rear)] = x;
    }
}

int Dequeue(struct Queue *q)
{
    int x = -1;
    if(q->rear == (q->front))
        printf("Queue is empty.\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
        q->Q[q->front] = 0;
    }
    return x;
}

void Display(struct Queue q)
{
    if(q.rear == q.front)
        printf("Queue is empty.");
    else
        for(int i = (q.front)+1; i <= q.rear; i++)
            printf("%d, ",q.Q[i]);
}

int main()
{
    struct Queue q;
    printf("Please Enter the queue's size:");
    scanf("%d", &q.size);
    //q.size = 10;
    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size*sizeof(int));

    Enqueue(&q, 15);
    Enqueue(&q, 30);
    Enqueue(&q, 15);
    Enqueue(&q, 30);

    Dequeue(&q);

    Display(q);

    return 0;
}
