//*******************Method A: for往下找*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

void FindPair(struct Array arr, int pairnum)
{
    int i = 0;
    int j = arr.Length-1;
    while(j > i)
    {
        if(arr.A[i] + arr.A[j] == 10)
        {
            printf("%d + %d = 10\n", arr.A[i], arr.A[j]);
            i++;
            j--;
            //break;
        }
        else if(arr.A[i] + arr.A[j] > 10)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    //struct Array arr = {{1,2,2,3,4,6,7,7,7,8},10,10};
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14},10,10};

    FindPair(arr,10);
}