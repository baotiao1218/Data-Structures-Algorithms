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

void Insert(struct Node *p, int num, int n)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int i;
    t->data = num;
    if(n==0)
    {
        t->next = p;
        first = t;
    }
    else
    {
        for(i=0; i<n-1 && p!=NULL; i++)
        {
            p = p->next;
        }
        if(i == n-1)
        {
            t->next = p->next;
            p->next = t;
        }
        else
        {
            printf("FAILED!\n");
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
    Insert(first,75339672,2);
    Display(first);

    return 0;
}
