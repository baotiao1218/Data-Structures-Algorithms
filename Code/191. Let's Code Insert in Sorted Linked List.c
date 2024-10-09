#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL;

void Create(int A[], int n)
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
}

void InsertSorted(struct Node *p, int num)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q;
    int i;
    t->data = num;

    if(p==NULL)
    {
        //Create
    }
    else
    {
        while(p!= NULL && p->data < num)
        {
            q = p;
            p = p->next;
        }
        if(p==NULL)
        {
            q->next = t;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
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
    Create(a,10);
    InsertSorted(first,75339672);
    Display(first);

    return 0;
}
