#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
    int arr1[10], n, i, j, tmp;

    printf("sort elements of array in ascending order :\n");
    
    printf("Input the size of array : ");
    scanf("%d", &n);
    printf("Input %d elements in the array :\n", n);
    
    for (i = 0; i < n; i++)
    {
        printf("element no.%d : ", i);
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr1[j] < arr1[i])
            {
                tmp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = tmp;
            }
        }
    }

    printf("\nElements of array in sorted ascending order:\n");
    for (i = 0; i < n; i++){
        printf("%d  ", arr1[i]);
    }
    printf("\n");

    return 0;
}