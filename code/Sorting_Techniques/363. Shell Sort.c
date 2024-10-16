#include <stdio.h>
#include <stdlib.h>


void Swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void ShellSort(int arr[], int n)
{
    int gap,i,j,temp;

    for(gap=n/2; gap>=1; gap/=2)
    {
        for(i=gap; i<n; i++)
        {
            temp = arr[i];
            j = i - gap;
            while(j >= 0 && arr[j] > temp)
            {
                arr[i] = arr[j];
                j = j - gap;
            }
            arr[j+gap] = temp;
        }
    }
}

int main()
{
    int arr[10] = {65,83,32,106,155,61,92,127,66,33};
    //int arr[10] = {6,8,3,10,15,6,9,12,6,3};

    ShellSort(arr,10);
    for(int i=0; i < 10; i++)
        printf("%d, ",arr[i]);

    return 0;
}
