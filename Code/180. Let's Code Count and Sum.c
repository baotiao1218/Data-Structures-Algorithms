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

int Count(struct Node *p)   // Count by while
{
    int num = 0;
    while(p!=NULL)
    {
        num++;
        p=p->next;
    }
    return num;
}

int CountR(struct Node *p)   // Count by Recursive
{
    if(p!=NULL)
    {
        return CountR(p->next)+1;
    }
    return 0;
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d, ",p->data);
        p=p->next;
    }
}

int Sum(struct Node *p)
{
    int result = 0;
    while(p!=NULL)
    {
        result = result + p->data;
        p = p->next;
    }
    return result;
}

int SumR(struct Node *p)
{
    if(p!=NULL)
    {
        int sum = p->data;
        return SumR(p->next) + sum;
    }
    return 0;
}

int main()
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    Create(first,a,10);

    printf("Counting by while loop: %d\n", Count(first));
    printf("Counting by recursive: %d\n", CountR(first));
    printf("Sum by while loop: %d\n", Sum(first));
    printf("Sum by recursive: %d\n", SumR(first));

    return 0;
}
