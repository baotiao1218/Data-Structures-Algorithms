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

int CheckSortedOrNot(struct Node *p)
{
    int last = p->data;
    while(p!=NULL)
    {
        if(p->data < last)
        {
            return 0;
        }
        last = p->data;
        p = p->next;
    }
    return 1;
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
    int a[] = {1,3,5,7,9,11,13,15,17,19,21};
    Create(a,11);

    if(CheckSortedOrNot(first))
    {
        printf("Sorted!\n");
    }
    else
    {
        printf("Not Sorted.\n");
    }
    Display(first);

    return 0;
}
