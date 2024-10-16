#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL,*second=NULL,*third=NULL,*head=NULL;

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
}

void CreateLoop(int A[], int n)
{
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next = head;  // for Loop
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

void DisplayLoop(struct Node *p)
{
    int flag = 0;

    do
    {
        flag = 1;
        printf("%d, ",p->data);
        p=p->next;
    }
    while(flag = 1 && p!= head);
}

int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    int b[] = {2,4,6,8,10};
    CreateLoop(a,10);

    //Display(head);
    DisplayLoop(head);

    return 0;
}


