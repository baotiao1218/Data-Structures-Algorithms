#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL,*second=NULL,*third=NULL;;

int isLoop(struct Node *first)
{
    struct Node *p, *q;
    p = q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = q?q->next:NULL;
    }
    while((p!=NULL) && (q!=NULL));

    return p == q ? 1 : 0;
}

void CreateA(int A[], int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next = first;  // for Loop
}

void CreateB(int A[], int n)
{
    struct Node *t,*last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Concat(struct Node *p, struct Node *q)
{
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d, ",p->data);
        p=p->next;
    }
}

int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    int b[] = {2,4,6,8,10};
    CreateA(a,10);
    CreateB(b,5);

    //Merge(first,second);
    //Display(second);

    printf("%d",isLoop(second));
    return 0;
}


