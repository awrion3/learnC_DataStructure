#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i = 0, j = 0, k = 0, arr[6], evenArr[6], oddArr[6];

	printf("Enter the array elements: ");
	for (i = 0; i < 6; i++)
		scanf("%d", &arr[i]);
		
	for (i = 0; i < 6; i++) {
		if (arr[i] % 2 != 0)
			oddArr[j++] = arr[i];
		else
			evenArr[k++] = arr[i];
	}

	printf("Even elements: ");
	for (i = 0; i < j; i++)
		printf("%d ", evenArr[i]);
	printf("\nOdd elements: ");
	for (i = 0; i < k; i++)
		printf("%d ", oddArr[i]);
	printf("\n");

	return 0;
}
