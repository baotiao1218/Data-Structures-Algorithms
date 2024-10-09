#include <stdio.h>
#include <stdlib.h>

void FindDupl (char *str)
{
    int hash[26] = {0};
    char dup = NULL;

    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            hash[str[i]-97]++;
            //printf("%d\n", (str[i]-97));
        }
        else {break;}
    }
    for(int i=0; i < 26; i++)
    {
        if(hash[i] > 1)
        {
            dup = i+97;
            printf("Duplicates found. %c \n", dup);
        }
    }
}
int main()
{
    char A[6] = "finding";
    FindDupl(A);

    return 0;
}
