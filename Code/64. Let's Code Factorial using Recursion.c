#include <stdio.h>
#include <stdlib.h>
int fact(int n)
{
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

int main()
{
    int r;
    r=fact(5);
    printf("%d ",r);
    return 0;
}
