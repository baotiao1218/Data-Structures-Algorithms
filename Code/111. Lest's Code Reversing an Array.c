#include <stdio.h>
#include <stdlib.h>

void Reverse1(int *p)  //Method A: 開新陣列
{
    int temp[5];

    for(int i=0, j=4;i<5,j>=0; i++,j--)
        temp[i] = p[j];


    p = temp;

    for(int i = 0; i < 5; i++)
        printf("%d, ",p[i]);
}

void Swap(int *p, int a, int b) //Method B: 對調數字
{
    if(a!=b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}

void Reverse2(int *p)
{
    for(int i=0, j=4;i<5,j>=0; i++,j--)
        Swap(p,i,j);

    for(int i = 0; i < 5; i++)
        printf("%d, ",p[i]);
}

int main()
{
    int *p = (int *)malloc(5*sizeof(int));

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    Reverse1(p);   //Method A: 開新陣列
    printf("\nMethod2:\n");
    Reverse2(p);   //Method B: 對調數字
}
