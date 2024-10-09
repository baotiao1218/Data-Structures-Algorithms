#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][2] = {{51,52},{53,54},{55,56}};
    printf("%d, %d\n", A[0][1],A[2][1]);


    int **p =(int **)malloc(3*sizeof(int));  //2D的話,要先宣告"指標的指標"

    p[0] = (int *)malloc(2*sizeof(int));  //宣告第二維度時，用p就好.
    p[1] = (int *)malloc(2*sizeof(int));
    p[2] = (int *)malloc(2*sizeof(int));

    p[0][0] = 41;
    p[0][1] = 42;
    p[1][0] = 43;
    p[1][1] = 44;
    p[2][0] = 45;
    p[2][1] = 46;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            printf("%d, ",p[i][j]);

    for(int i = 0; i < 3; i++)  //釋放每一行
       free(p[i]);
        //for(int j = 0; j < 2; j++)  //不須釋放整個元素,因為當你釋放 p[i] 時，系統會釋放整個 p[i] 所指向的記憶體塊，不需要逐個釋放其中的元素。
            //free(p[i][j]);

    free(p); //釋放最外層指標

    printf("---- %d", p[1][0]);
}

/*
Q: 那這樣看起來，其實只要釋放free(p)就好了,並不需要free(p[i])?


ChatGPT:
釋放動態分配的多維陣列時，正確的做法是首先釋放每一行的記憶體，然後再釋放最外層的指標。
這是因為在多維陣列的動態記憶體分配中，每一行的記憶體是獨立分配的。
直接釋放 p 只會釋放最外層的指標，而不會釋放每一行的記憶體，這會導致記憶體洩漏。


*/
