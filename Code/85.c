#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;

    p = (int *)malloc(3*sizeof(int));
    q = (int *)malloc(5*sizeof(int));

    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    printf("%d\n",p[0]);

    for(int i = 0; i < 3; i++)
        q[i] = p[i];

    q=p;

    printf("%d\n", q[1]);

    for(int i = 0; i < 3; i++) {
        free(p[i]); //釋放heap的array的各值
    }

    free(p);  //釋放指標本身
    printf("%d",p[2]); //驗證P是不是被釋放掉了

}


那這樣看起來，其實只要釋放free(p)就好了,並不需要free(p[i])?
ChatGPT
釋放動態分配的多維陣列時，正確的做法是首先釋放每一行的記憶體，然後再釋放最外層的指標。這是因為在多維陣列的動態記憶體分配中，每一行的記憶體是獨立分配的。直接釋放 p 只會釋放最外層的指標，而不會釋放每一行的記憶體，這會導致記憶體洩漏。