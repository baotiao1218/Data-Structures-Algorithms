#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}**hashNode = NULL;

void SortedInsert(struct Node **hashT, int key)
{
    struct Node *p = *hashT, *t, *q;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;

    if(*hashT == NULL)
        *hashT = t;
    else
    {
        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }

        if(p == *hashT)
        {
            t->next = *hashT;
            *hashT = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void Insert(struct Node **p, int key)
{
    SortedInsert(&p[key%10], key);
};

struct Node *Search(struct Node **ht, int key)
{
    struct Node *p = ht[key%10];

    while(p!=NULL)
    {
        if(p->data == key)
            return p;
        p = p->next;
    }

    return NULL;
};

int main()
{
    hashNode = (struct Node **)malloc(10*sizeof(struct Node *));

    for(int i=0;i<10;i++)
        hashNode[i] = NULL;

    Insert(hashNode,12);
    Insert(hashNode,22);
    Insert(hashNode,42);

    struct Node *x = Search(hashNode, 22);
    printf("%d",x);

    return 0;
}
