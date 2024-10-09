#include <stdio.h>
#include <stdlib.h>

void Sortcheck(int *arr)  //Method A: 開新陣列
{
    int last = -999;

    size_t n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            printf("unsorted!!!!\n");
            return 0;
        }
    }
    printf("sorted~");
}


int main()
{
    int sorted[5] = {1,2,3,4,5};
    int unsorted[5] = {5,2,3,1,4};

    Sortcheck(sorted);
    Sortcheck(unsorted);
}
