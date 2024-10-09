#include <stdio.h>
#include <stdlib.h>

void Merge (int *arr1,int *arr2,int *merged)
{
    int i=0, j=0, k=0;
    while(i<5&&j<5)
    {
        if(arr1[i] < arr2[j])    // 比較小的要在下面(先加)，不然大的一直++就飽了
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    for(;i<5;i++)
        merged[k++] = arr1[i];
    for(;j<5;j++)
        merged[k++] = arr2[j];

}
int main()
{
    int arr1[5] = {1,3,5,7,9};
    int arr2[5] = {2,4,6,8,10};
    int merged[10];

    Merge(arr1,arr2,merged);

    for(int i=0; i<10; i++)
        printf("%d, ",merged[i]);

    return 0;
}
