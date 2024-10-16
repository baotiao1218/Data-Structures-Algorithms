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
    if((q->rear + 1) % q->size == q->front)
        printf("Queue is full.\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }

}

int Dequeue(struct Queue *q)
{
    int x = -1;
    if(q->rear == (q->front))
        printf("Queue is empty.\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
        q->Q[q->front] = 0;
    }
    return x;
}

void Display(struct Queue q)
{
    if(q.rear == q.front)
        printf("Queue is empty.(Display) \n");
    else
    {
        int i = q.front;

        do
        {
            printf("%d, ",q.Q[(++i)%q.size]);
        }while((i%q.size) != q.rear);
    }
}

int main()
{
    struct Queue q;
    printf("Please Enter the queue's size:");
    scanf("%d", &q.size + 1);
    //q.size = 10;
    q.front = q.rear = 0;
    q.Q = (int *)malloc(q.size*sizeof(int));

    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Dequeue(&q);
    Dequeue(&q);
    Enqueue(&q, 5);

    Display(q);

    return 0;
}
