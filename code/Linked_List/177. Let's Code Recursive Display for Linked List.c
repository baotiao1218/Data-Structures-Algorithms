#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

};

void Create(struct Node *first, int A[], int n)
{
    struct Node *t,*last;
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

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d, ",p->data);
        p=p->next;
    }
}

void DisplayR(struct Node *p)   //Recursive
{
    if(p!=NULL)
    {
        printf("%d, ",p->data);
        DisplayR(p->next);
    }
}

int main()
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    Create(first,a,10);

    DisplayR(first);

    return 0;
}
