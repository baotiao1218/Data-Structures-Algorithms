#include <stdio.h>
#include <stdlib.h>
void swap(int a[],int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void InsertSort(int a[], int n)
{
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i-1;

        while(j >= 0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = x;
    }
    printf("%d\n",count);
}

int main()
{
    int arr[5] = {8,5,7,3,2};
    InsertSort(arr,5);

    for(int i = 0; i < 5; i++)
        printf("%d,",arr[i]);

    return 0;
}
