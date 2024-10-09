#include <stdio.h>
#include <stdlib.h>

void RevStr (char *str)
{
    char revstr[6];
    int i = 0;
    int j = 4;

    while(str[i] != '\0')
    {
        revstr[i++] = str[j--];
    }

    str = revstr;

    for(int i=0; str[i] != '\0'; i++)
    {
        printf("%c",str[i]);
    }
}
int main()
{
    char A[6] = "Apple";
    RevStr(A);

    return 0;
}
