#include <stdio.h>
#include <stdlib.h>

void FindDupl_Bitwise (char *str)
{
    int bt = 0;

    for(int i=0; str[i]!= '\0'; i++)
    {
        int x = 1;
        x = x << (str[i]-97);
        if((bt&x) > 0)
        {
            printf("Duplicate! %c \n", str[i]);
        }
        else
        {
            bt = bt|x;  //用於bitwise的or是|, 邏輯的or才是||.
        }
    }
}
int main()
{
    char A[8] = "finding";
    FindDupl_Bitwise(A);

    return 0;
}
