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

int Delete(int a[], int n)
{
    int x = a[0];
    int i = 0;
    int j = (i*2)+1;
    a[0] = a[n-1];

    while(j < n-1)
    {
        if(a[j] < a[j+1])
            j = j+1;

        if(a[j] > a[i])
        {
            swap(a,i,j);
            i = j;
            j = j*2+1;
        }
        else
            break;
    }
    return x;
}
int main()
{
    int arr[7] = {40,35,30,15,10,25,5};
    Delete(arr,7);

    for(int i = 0; i < 7; i++)
        printf("%d,",arr[i]);

    return 0;
}
