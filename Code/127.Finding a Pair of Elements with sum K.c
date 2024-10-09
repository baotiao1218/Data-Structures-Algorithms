//*******************Method A: for往下找*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindPair(struct Array arr)
{
    for(int i = 0; i < arr.Length; i++)
    {
        for(int j = i+1; j < arr.Length;j++)
        {
            if(arr.A[j] + arr.A[i] == 10)
            {
                printf("%d + %d = 10\n", arr.A[i], arr.A[j]);
            }
        }
    }
}

int main()
{
    //struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14},10,10};

    FindPair(arr);
}


//*******************Method B: Hash table.*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindPair(struct Array arr, int pairnum)
{
    int hash[21] = {-999};
    for(int i = 0; i < arr.Length; i++)
    {
        hash[arr.A[i]]++;
        if(hash[pairnum-arr.A[i]] > 0)
        {
            printf("%d + %d = %d\n", arr.A[i], pairnum-arr.A[i], pairnum);
        }
    }
}

int main()
{
    //struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14},10,10};

    FindPair(arr,10);
}