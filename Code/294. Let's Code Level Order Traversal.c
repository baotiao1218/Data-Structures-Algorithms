
#include "Queue.h"
#include "Stack.h"

struct Node* root = NULL;

void TreeCreate()
{
    struct Node *t,*p;
    int x;
    struct Queue q;
    QueueCreate(&q,100);
    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Queue_enqueue(&q,root);
    while(!Queue_isEmpty(q))
    {
        p = Queue_dequeue(&q);
        printf("Enter Left child of %d : ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Queue_enqueue(&q,t);
        }
        printf("Enter Right child of %d : ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Queue_enqueue(&q,t);
        }
    }
}

void Preorder(struct Node* p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node* p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void iterativePreorder(struct Node* p)
{
    struct Node *t = p;
    struct Stack st;
    StackCreate(&st,100);
    while(t != NULL || !Stack_isEmpty(st))
    {
        if(t != NULL)
        {
            printf("%d, ", t->data);
            Stack_push(&st,t);
            t = t->lchild;
        }
        else
        {
            t = Stack_pop(&st);
            t = t->rchild;
        }
    }
}

void iterativeInorder(struct Node* p)
{
    struct Stack st;
    StackCreate(&st,100);

    while(p != NULL || !Stack_isEmpty(st))
    {
        if(p != NULL)
        {
            Stack_push(&st,p);
            p = p->lchild;
        }
        else
        {
            p = Stack_pop(&st);
            printf("%d, ", p->data);
            p = p->rchild;
        }
    }

}

void iterativePostorder(struct Node* p)
{
    struct Stack st;
    StackCreate(&st, 100);
    long int temp;

    while(p != NULL || !Stack_isEmpty(st))
    {
        if(p != NULL)
        {
            Stack_push(&st, p);
            p = p->lchild;
        }
        else
        {
            temp = Stack_pop(&st);
            if(temp > 0)
            {
                Stack_push(&st,-temp);
                p = (struct Node*) temp;
                p = p->rchild;
            }
            else
            {
                p = (struct Node*) -temp;
                printf("%d, ",p->data);
                p = NULL;
            }
        }
    }
}

void LevelOrder(struct Node* p)
{
    struct Queue q;
    QueueCreate(&q, 100);

    //init
    Queue_enqueue(&q, p);

    while(!Queue_isEmpty(q))
    {
        p = Queue_dequeue(&q);
        if(p->lchild != NULL)
            Queue_enqueue(&q, p->lchild);
        if(p->rchild != NULL)
            Queue_enqueue(&q, p->rchild);

        printf("%d,", p->data);
    }
}

int main()
{
    TreeCreate();

    printf("Level Order: ");
    LevelOrder(root);

    return 0;
}
