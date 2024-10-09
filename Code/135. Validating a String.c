#include <stdio.h>
#include <stdlib.h>

void ValStr (char *str)
{
    for(int i=0; str[i] != '\0'; i++)
    {
        if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) //65~90, 97~122
        {
            printf("%c, INVALID STRING.\n",str[i]);
            break;
        }
    }
}
int main()
{
    char A[6] = "Apple";
    char B[6] = "App%&";
    ValStr(A);
    ValStr(B);

    return 0;
}
