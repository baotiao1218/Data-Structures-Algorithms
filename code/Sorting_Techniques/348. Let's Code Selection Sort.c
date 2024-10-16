#include <stdio.h>
#include <stdlib.h>
void swap(int a[],int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void SelectionSort(int a[], int n)
{
    int count = 0;
    int i,j,k;

    for(i = 0; i < n; i++)
    {
        count++;
        j = k = i;
        for(j = i; j < n; j++)
            if(a[j] < a[k])
                k = j;

        swap(a,i,k);
    }

    printf("%d\n",count);
}

int main()
{
    int arr[6] = {8,6,3,2,5,4};
    SelectionSort(arr,6);

    for(int i = 0; i < 6; i++)
        printf("%d,",arr[i]);

    return 0;
}
