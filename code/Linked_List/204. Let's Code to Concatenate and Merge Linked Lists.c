//Concat

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL,*second=NULL,*third=NULL;;

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
    int b[] = {1,3,5,7,9};
    CreateA(a,10);
    CreateB(b,5);

    Concat(first,second);
    Display(first);

    return 0;
}


//Merge
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL,*second=NULL,*third=NULL;;

void Merge(struct Node *first, struct Node *second)
{
    struct Node *last, *third;

    if (first->data < second->data) {
        third = last = first;
        first = first->next;
    } else {
        third = last = second;
        second = second->next;
    }

    while((first != NULL) && (second != NULL))
    {
        if((first->data) < (second->data))
        {
            last->next = first;
            first = first->next;
            last = last->next;
        }
        else
        {
            last->next = second;
            second = second->next;
            last = last->next;
        }
    }
    while(first != NULL)
    {
        last->next = first;
        first = first->next;
        last = last->next;
    }
    while(second != NULL)
    {
        last->next = second;
        second = second->next;
        last = last->next;
    }
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

    Merge(first,second);
    Display(first);

    return 0;
}
