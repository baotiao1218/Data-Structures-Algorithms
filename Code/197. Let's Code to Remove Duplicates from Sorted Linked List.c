
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

void DeleteDup(struct Node *p)
{
    struct Node *q = NULL;
    int last = p->data;
    q = p;
    p = p->next;
    while(p!=NULL)
    {
        if(p->data == last)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            last = p->data;
            q = p;
            p = p->next;
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
    int a[] = {1,3,5,7,7,7,7,7,9,11,13,13,13,19,21};
    Create(a,15);

    DeleteDup(first);
    Display(first);

    return 0;
}
