//*******************Method A*******************
#include <stdio.h>
#include <stdlib.h>
int fib(int n)
{   
    return (n-1)+n;
}

int main()
{
    printf("%d",fib(7));  //in Fibonacci, 7的下一個數字為何?
}

//*******************Method B: Recursion*******************
#include <stdio.h>
#include <stdlib.h>
int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-2) + fib(n-1);
}

int main()
{
    printf("%d \n",fib(7));
    return 0;
}
