#include <stdio.h>
#include <stdlib.h>

void Perm (char str[], int k)
{
    static char res[4];
    static int a[3] = {0};

    if(str[k] == '\0')
    {
        printf("%s\n", res);
    }
    else
    {
        for(int i=0; str[i]!='\0'; i++)
        {
            if(a[i] == 0)
            {
                res[k] = str[i];
                a[i] = 1;
                Perm(str, k+1);
                a[i] = 0;
            }
        }
    }
}
int main()
{
    char str[4] = "ABC";
    Perm(str,0);

    return 0;
}


// Method B: Swap

#include <stdio.h>
#include <stdlib.h>
void Swap(char str[], int a, int b)
{
    char temp = NULL;
    temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}

void Perm(char str[], int l, int h)
{
    if(l == h)
    {
        printf("%s\n",str);
    }
    else
    {
        for(int i=l;str[i] != '\0';i++)
        {
            Swap(str, i, l);
            Perm(str, l+1 ,h);
            Swap(str, i, l);
        }
    }
}
int main()
{
    char str[4] = "ABC";
    Perm(str,0,2);

    return 0;
}
