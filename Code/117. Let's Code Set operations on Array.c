#include <stdio.h>
#include <stdlib.h>

void Set (int *arr1,int *arr2,int *set)
{
    int i=0, j=0, k=0;

    while(i<5&&j<5)
    {
        if(arr1[i] == arr2[j])
        {
            set[k++] = arr1[i];
            i++;j++;
        }
        else if(arr1[i] > arr2[j])
        {
            j++;
        }
        else if(arr2[j] > arr1[i])
        {
            i++;
        }
    }

}
int main()
{
    int arr1[5] = {1,2,3,4,9};
    int arr2[5] = {2,4,6,8,9};
    int set[10];

    Set(arr1,arr2,set);

    for(int i=0; i<10; i++)
        printf("%d, ",set[i]);

    return 0;
}
