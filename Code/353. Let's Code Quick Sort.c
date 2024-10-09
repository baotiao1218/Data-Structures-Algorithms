#include <stdio.h>
#include <stdlib.h>
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int Partition(int a[], int l, int h)
{
    int i = l, j = h;

    while(i < j)
    {
        do{i++;}while(a[i] <= a[l]);
        do{j--;}while(a[j] > a[l]);

        if(i < j)
        {
            printf("%d, %d<-->",a[i],a[j]);
            swap(&a[i],&a[j]);
            printf("%d, %d\n",a[i],a[j]);
        }
    }
    swap(&a[l],&a[j]);
    printf("%d, %d\n",a[i],a[j]);

    return j;
}

void QuickSort(int a[],int l,int h)
{
    int j;
    if(l < h)
    {
        j = Partition(a,l,h);

        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

int main()
{
    int arr[9] = {50,70,60,90,40,80,10,20,30};
    QuickSort(arr,0,9);

    for(int i = 0; i < 9; i++)
        printf("%d,",arr[i]);

    return 0;
}
