#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

}*first=NULL,*second=NULL,*third=NULL,*head=NULL, *doublyLL=NULL;

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

void InsertInLoop(struct Node *head, int n, int x)
{
    struct Node *p, *t;
    p = head;
    for(int i = 0; (i < n-1); i++)
        p = p->next;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = p->next;
    p->next = t;
}

void DeleteInLoop(struct Node *p, int n)
{
    struct Node *last;

    if(n == 0)
    {
        do
        {
            last = p;
            p = p->next;
        }
        while(p != head);
    }
    else
    {
        for(int i = 0; (i < n); i++)
        {
            last = p;
            p = p->next;
        }
    }

    last->next = p->next;
    head = p->next;
    free(p);
}

void CreateDoublyLL(int A[], int n)
{
    struct Node *t,*last;
    doublyLL = (struct Node *)malloc(sizeof(struct Node));
    doublyLL->prev=NULL;
    doublyLL->data=A[0];
    doublyLL->next=NULL;
    last=doublyLL;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->prev=last;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void InsertDoublyLL(struct Node *p, int n, int x)
{
    struct Node *t;
    for(int i = 0; i < n-1; i++)
        p = p->next;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = p->next;
    t->prev = p->prev;
    p->prev->next = t;
    p->next->prev = t;
    free(p);
}

void ReverseDoublyLL(struct Node *p)
{
    //參數:*t
    struct Node *t;
    //2. (while p!=null)  t = p, p->next = p->prev, p->prev -> t->next, p = p->next;
    while(p != NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;

        if(p!=NULL && p->next==NULL)
            doublyLL = p;
    }
}
int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    int b[] = {2,4,6,8,10};
    CreateDoublyLL(a,10);
    Display(doublyLL);
    printf("\n");
    ReverseDoublyLL(doublyLL);
    Display(doublyLL);
    return 0;
}



