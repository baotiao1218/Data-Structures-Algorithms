//*******************Method A(Single): n(n+1)/2*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindDuplicate_A(struct Array arr)
{
    int lastduplicate = -999;
    for(int i = 0; i < arr.Length-1; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            if (arr.A[i] != lastduplicate)
            {
                lastduplicate = arr.A[i];
                printf("Found Duplicate! Num: %d\n", arr.A[i]);
            }
        }
    }
}

int main()
{
    struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    //struct Array arr = {{7,8,3,11,6,1,2,4},10,10};

    FindDuplicate_A(arr);
}


//*******************Method B: 找重複數量*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindDuplicate_A(struct Array arr)
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
    struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    //struct Array arr = {{7,8,3,11,6,1,2,4},10,10};

    FindDuplicate_A(arr);
}