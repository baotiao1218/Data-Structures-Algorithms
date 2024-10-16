
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void Insert(int key)
{
    struct Node *t,*r,*p;
    p = t = r = root;

    if(root == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->rchild = t->lchild = NULL;
        root = t;
        return;
    }
    if(p->data == key)
        return;

    while(p!=NULL)
    {
        r = p;
        if(p->data > key)
            p = p->lchild;
        else if(p->data < key)
            p = p->rchild;
        else
            return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->rchild = t->lchild = NULL;

    if(key > r->data)
        r->rchild = t;
    else
        r->lchild = t;
}

void Inorder(struct Node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        printf("%d, ", p->data);
        Inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
    struct Node *p = root;

    while(p != NULL)
    {
        if(p->data == key)
            return p;
        else if(p->data > key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}

struct Node *RInsert(struct Node *p, int key)
{
    if(p == NULL)
    {
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->rchild = t->lchild = NULL;
        return t;
    }
    else
        if(key > p->data)
            p->rchild = RInsert(p->rchild, key);
        else
            p->lchild = RInsert(p->lchild, key);
    return p;
};

int main()
{
    root = RInsert(root,10);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,8);
    RInsert(root,30);

    Inorder(root);
    /*
    struct Node *result = Search(12321);
    if(result != NULL)
        printf("%d, ", result->data);
    else
        printf("IS NULL!");
        */
    return 0;
}
