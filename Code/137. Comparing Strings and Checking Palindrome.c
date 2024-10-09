#include <stdio.h>
#include <stdlib.h>

void CheckPalindrome (char *str)
{
    int i = 0;
    int j = 4;

    while(str[i] != '\0')
    {
        printf("%c %c,",str[i],str[j]);
        if(str[i] != str[j])
        {
            printf("This string is not a palindrome.");
            break;
        }
        else
        {
            i++;
            j--;
        }
    }
}
int main()
{
    char A[6] = "madam";
    CheckPalindrome(A);

    return 0;
}
