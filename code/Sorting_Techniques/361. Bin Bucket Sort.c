#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL;

void Insert(struct Node **p, int num, int n)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int i;
    t->data = num;
    if(n==0)
    {
        t->next = *p;
        *p = t;
    }
    else
    {
        for(i=0; i<n-1 && p!=NULL; i++)
        {
            *p = (*p)->next;
        }
        if(i == n-1)
        {
            t->next = (*p)->next;
            (*p)->next = t;
        }
        else
        {
            printf("FAILED!\n");
        }
    }
}

int Delete(struct Node **p, int n)
{
    int i;
    int x;

    x = (*p)->data;
    *p = (*p)->next;

    return x;
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d, ",p->data);
        p=p->next;
    }
}

void BinSort(int arr[], int n)
{
    int max,i,j;
    max = i = j = 0;

    for(i=0; i<n; i++)
        if(arr[i] > max)
            max = arr[i];

    struct Node **bins;
    bins = (struct Node **)malloc((max+1)*sizeof(struct Node));

    for(j=0; j<max+1; j++)
        bins[j] = NULL;

    for(i=0; i<n; i++)
    {
        Insert(&bins[arr[i]],arr[i],0);
    }

    i = j = 0;

    while(j<max+1)
        if(bins[j] == NULL)
            j++;
        else
        {
            arr[i++] = Delete(&bins[j],0);
        }

}

int main()
{
    int arr[10] = {6,8,3,10,15,6,9,12,6,3};

    BinSort(arr,10);
    for(int i=0; i < 10; i++)
        printf("%d, ",arr[i]);

    return 0;
}
