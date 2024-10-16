#include <stdio.h>
#include <stdlib.h>
void swap(int a[],int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void BubbleSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0;j < n-1-i; j++)
        {
            if(a[j] > a[j+1])
                swap(a,j,j+1);
        }
    }
}

int main()
{
    int arr[5] = {8,5,7,3,2};
    BubbleSort(arr,5);

    for(int i = 0; i < 5; i++)
        printf("%d,",arr[i]);

    return 0;
}
