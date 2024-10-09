#include <stdio.h>
#include <stdlib.h>
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void CountSort(int arr[],int n)
{
    int i, indArr = 0, indHash = 0, max = -1;

    for(i = 0; i < n; i++)
        if(arr[i] > max)
            max = arr[i];

    int hash[max+1];

    for (i = 0; i <= max; i++)
        hash[i] = 0;

    for(i = 0; i < n; i++)
        hash[arr[i]]++;

    while(indArr < n && indHash < max+1)
    {
        while(hash[indHash] > 0)
        {
            arr[indArr++] = indHash;
            hash[indHash]--;
        }

        indHash++;
    }
}

int main()
{
    int arr[9] = {50,70,60,90,40,80,10,20,30};
    CountSort(arr,9);

    for(int i = 0; i < 9; i++)
        printf("%d,",arr[i]);

    return 0;
}