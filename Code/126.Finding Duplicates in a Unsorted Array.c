//*******************Method A: 自己研發版*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindDuplicate_C(struct Array arr)
{
    //struct Array hash = {{},arr.Size,arr.Length};
    int hash[21] = {-999};
    for(int i = 0; i < arr.Length; i++)
    {
        hash[arr.A[i]] += 1;
    }

    //print
    for(int i = 0; i < arr.Length; i++)
    {
        if(hash[i] > 1)
        {
            printf("num: %d, times: %d\n", i, hash[i]);
        }
    }
}

int main()
{
    //struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    struct Array arr = {{1,7,8,7,4,3,6,7,2,2},10,10};

    FindDuplicate_C(arr);
}

//*******************Method B: for一直往下找*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindDuplicate_D(struct Array arr)
{
    //struct Array hash = {{},arr.Size,arr.Length};
    for(int i = 0; i < arr.Length; i++)
    {
        int count = 1;
        if(arr.A[i] != -999)
        {
            for(int j = i+1; j < arr.Length;j++)
            {
                if(arr.A[j] == arr.A[i])
                {
                    arr.A[j] = -999;
                    count++;
                }
            }
            if(count > 1)
            {
                printf("num:%d, times:%d\n", arr.A[i], count);
            }
        }
    }
}

int main()
{
    //struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    struct Array arr = {{1,7,8,7,4,3,6,7,2,2},10,10};

    FindDuplicate_D(arr);
}