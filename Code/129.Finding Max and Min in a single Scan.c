#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindMaxMin(struct Array arr)
{
    int max = arr.A[i];
    int min = arr.A[i];
    for(int i = 1; i < arr.Length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
        if(min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    printf("Max:%d, Min:%d", max, min);
}

int main()
{
    //struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14},10,10};

    FindMaxMin(arr);
}