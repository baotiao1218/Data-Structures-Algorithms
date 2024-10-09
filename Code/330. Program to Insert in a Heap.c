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

int main()
{
    int arr[10] = {40,35,15,30,10,12,6,5,20,50};

    Insert(arr,9);

    for(int i = 0; i < 10; i++)
        printf("%d,",arr[i]);

    return 0;
}
