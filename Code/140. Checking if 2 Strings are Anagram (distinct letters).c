#include <stdio.h>
#include <stdlib.h>

void FindAnagram (char *str1, char *str2)
{
    int hash[26] = {0};
    int str1_length = 0, str2_length = 0;

    while(str1[str1_length] != '\0')//檢測長度是否相同
    {
        str1_length++;
    }

    while(str2[str2_length] != '\0')//檢測長度是否相同
    {
        str2_length++;
    }

    if(str1_length != str2_length)
    {
        printf("not anagram. wrong str num. \n");
        return 0;
    }

    for(int i=0; i < str1_length; i++)
    {
        hash[str1[i]-'a']++;
        hash[str2[i]-'a']--;
    }

    for(int i=0; i < 26; i++)
    {
        if(hash[i] != 0)
        {
            printf("Not anagram!");
            return 0;
        }
    }
    printf("Good! they are anagram");

}
int main()
{
    char A[11] = "lesserafim";
    char B[11] = "imfearless";

    FindAnagram(A,B);

    return 0;
}
