
//*******************Method A(Single): n(n+1)/2*******************
#include <stdio.h>

struct Array
{
    int A[20];
    int Size;
    int Length;
};

int FindMissing_A(struct Array arr)
{
    int last_num = arr.A[arr.Length-1];
    int sum = last_num*(last_num+1)/2;
    int sum_arr;

    for(int i = 0; i < arr.Length; i++)
    {
        sum_arr += arr.A[i];
    }

    return sum-sum_arr;
}

int main()
{
    struct Array arr = {{1,2,3,4,6,7,8,9,10},10,9};
    
    //Method A: n(n+1)/2
    printf("%d", FindMissing_A(arr));
}



 //*******************Method B(Single/Multiple)*******************
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
            printf("Missing: %d\n", diff+i);
            diff++;
        }
   }
}

int main()
{
    struct Array arr = {{1,2,3,4,6,7,8,9,10},10,9};

    //Method B: 
    FindMissing_B(arr);
}