#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5];
    int *p;

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    for(int i = 0; i < 5; i++)
        printf("%d, ",a[i]);

    printf("\n");

    p = (int *)malloc(5*sizeof(int));

    p[0] = 11;
    p[1] = 22;
    p[2] = 33;
    p[3] = 44;
    p[4] = 55;

    for(int i = 0; i < 5; i++)
        printf("%d, ",p[i]);
}
