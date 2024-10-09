#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

int FindMissing_B(struct Array arr)
{
   int diff = arr.A[0]-0;

   for(int i = 0; i < arr.Length; i++)
   {
        if(arr.A[i]-i != diff)
        {
            //printf("Missing: %d\n", diff+i);
            while(arr.A[i]-i > diff)
            {
                printf("Missing: %d\n", diff+i);
                diff++;
            }
        }
   }
}

int main()
{
    struct Array arr = {{1,2,3,4,6,7,8,11},10,10};

    //Method B: 
    FindMissing_B(arr);
}