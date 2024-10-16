
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

int Height(struct Node *p)
{
    int x = 0, y = 0;
    if(p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return (x>y)?x+1:y+1;
}

struct Node *InPre(struct Node *p)
{

    while(p!=NULL && p->rchild != NULL)
        p = p->rchild;

    return p;
};

struct Node *InSucc(struct Node *p)
{

    while(p!=NULL && p->lchild != NULL)
        p = p->lchild;

    return p;
};


struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if(p == NULL) //!!
        return NULL;

    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL; //!!
        free(p);
        return NULL;
    }

    if(p->data > key)
        p->lchild = Delete(p->lchild, key);
    else if(p->data < key)
        p->rchild = Delete(p->rchild, key);
    else //(p->data == key)
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);  //極右
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);  //極左
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
};

struct Node *GenBSTFromPre(int pre[], int n)
{
    struct Node *p,*t;
    struct Stack st;
    StackCreate(&st, 100);

    int i = 0;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = pre[i++];
    t->lchild = t->rchild = NULL;
    root = p = t;

    while(i < n)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = pre[i];
        t->lchild = t->rchild = NULL;
        if(p->data > pre[i])
        {
            p->lchild = t;
            Stack_push(&st, p);
            p = t;
            i++;
        }
        else
        {
            while(pre[i] > StackTop(st)->data && Stack_isEmpty(st))   //Should be !Stack_isEmpty(st), idk why it's not work...
            {
                p = Stack_pop(&st);
            }
            p->rchild = t;
            p = t;
            i++;
        }
    }
    return root;
};

void Preorder(struct Node* p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}


int main()
{
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};

    root = GenBSTFromPre(pre, sizeof(pre)/sizeof(int));

    Preorder(root);
    /*
    struct Node *result = Search(12321);
    if(result != NULL)
        printf("%d, ", result->data);
    else
        printf("IS NULL!");
        */
    return 0;
}
