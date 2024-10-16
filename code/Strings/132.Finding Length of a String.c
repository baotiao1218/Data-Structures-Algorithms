#include <stdio.h>

int FindStrLength(char S[])
{
    int count = 0;
    for(int i = 0; S[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char S[] = "Welcome";
    printf("%d",FindStrLength(S));
}