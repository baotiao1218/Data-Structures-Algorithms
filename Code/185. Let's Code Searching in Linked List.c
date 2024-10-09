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

int Search(struct Node *p, int target)
{
    while(p!=NULL)
    {
        if(p->data == target)
        {
            return target;
        }
        p = p->next;
    }
    return 0;
}

int SearchImproved(struct Node *p, int key)  //把結果擺到第一個
{
    struct Node *q = NULL;
    while(p!=NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return key;
        }
        q=p;
        p = p->next;
    }
    return 0;
}

int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    Create(a,10);
    printf("Found: %d\n",Search(first,7));
    printf("Found by Improved Search: %d\n",SearchImproved(first,7));

    struct Node *v = first;
    while(v!=NULL)
    {
        printf("%d, ",v->data);
        v = v->next;
    }
    return 0;
}
