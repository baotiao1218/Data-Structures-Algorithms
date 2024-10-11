#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Enqueue_front(struct Queue *q, int x)
{
    if(q->rear == (q->size -1))
        printf("Queue is full.");

    else
    {
        q->Q[q->front] = x;
        q->front--;
        //q->size[++(q->rear)] = x;
    }
}

void Enqueue_rear(struct Queue *q, int x) //v
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

int Dequeue_rear(struct Queue *q) //v
{
    int x = -1;
    if(q->rear == (q->front))
        printf("Queue is empty.\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int Dequeue_front(struct Queue *q)
{
    int x = -1;
    if(q->rear == (q->front))
        printf("Queue is empty.\n");
    else
    {
        x = q->Q[q->rear];
        q->rear--;
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

    Enqueue_rear(&q, 1);
    Enqueue_rear(&q, 3);
    //Dequeue_rear(&q);
    Enqueue_rear(&q, 5);
    Enqueue_rear(&q, 7);
    Enqueue_front(&q, 0);
    Enqueue_rear(&q, 9);
    //Dequeue_front(&q);


    Display(q);

    return 0;
}
