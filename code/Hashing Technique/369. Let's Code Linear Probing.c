#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}**hashNode = NULL;

int LinearInsert(int a[],int key)
{
    int hashindex,i;
    hashindex = i = 0;
    do
    {
        hashindex = ((key%10)+i)%10;
        i++;
    }while(a[hashindex] != -1 && i<10);

    if(i<10)
    {
        a[hashindex] = key;
        return 1;
    }
    else
        return 0;
}

int Search(int a[], int key)
{
    int hashindex,i;
    hashindex = i = 0;

    do
    {
        hashindex = ((key%10)+i)%10;
        i++;
    }while(a[hashindex]!= -1 && i<10);

    if(a[hashindex] == key)
        return a[hashindex];
    else
        return 0;
}

int main()
{
    int arr[10];

    for(int i=0;i<10;i++)
        arr[i] = -1;

    LinearInsert(arr,15);
    LinearInsert(arr,25);

    for(int i=0;i<10;i++)
        printf("%d,",arr[i]);

    return 0;
}
