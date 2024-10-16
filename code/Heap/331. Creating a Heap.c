#include <stdio.h>
#include <stdlib.h>
void swap(int a[],int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Insert(int a[], int n)
{
    int i = n;

    while(a[i] > a[i/2])
    {
        swap(a,i,i/2);
        i = i/2;
    }
}

void CreateHeap(int a[], int n)
{
    if(a[1] > a[0])
        swap(a,1,0);

    for(int i = 2; i < n; i++)
    {
        while(a[i] > a[i/2])
        {
            swap(a,i,i/2);
            i = i/2;
        }
    }
}

int main()
{
    int arr[10] = {40,35,15,30,10,12,6,5,20,50};
    int arr2[] = {10,20,30,25,5,40,35};

    Insert(arr,9);
    CreateHeap(arr2,7);

    for(int i = 0; i < 7; i++)
        printf("%d,",arr2[i]);

    return 0;
}
