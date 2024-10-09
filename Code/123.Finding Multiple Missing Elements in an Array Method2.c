#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindMissing_C(struct Array arr)
{
    struct Array hash = {{},arr.Length+1,arr.Length+1};

    for(int i = 0; i < arr.Length; i++)
    {
        //printf("%d, ",arr.A[i]);
        hash.A[arr.A[i]]++;
    }
    for(int i = 0; i < hash.Length; i++)
    {
        if(hash.A[i] == 0)
        {
            printf("%d, ", i);
        }
    }
}

int main()
{
    //struct Array arr = {{1,2,3,4,6,7,8,11},10,10};
    struct Array arr = {{7,8,3,11,6,1,2,4},10,10};

    FindMissing_C(arr);
}