#include <stdio.h>

int main()
{
    char S[] = "how are     you";
    
    int words = 0;
    int vowels = 0;
    for(int i = 0; S[i] != '\0'; i++)
    {
        if(S[i] == 'a'||S[i] == 'e'||S[i] == 'i'||S[i] == 'o'||S[i] == 'u')
        {
            vowels++;
        }
        if((S[i] != ' ' && S[i+1] == ' ')||S[i+1] =='\0')
        {
            words++;
        }
    }
    printf("Words:%d, Vowels:%d",words, vowels);
}