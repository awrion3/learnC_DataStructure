#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i = 0, j = 0, temp, arr[5];
	printf("\nEnter elements:\n");
	for (i = 0; i < 5; i++)
	{
		printf("Enter arr[%d]:", i);
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 5 - 1; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("\nAfter Sorting");
	for (i = 0; i < 5; i++)
	{
		printf("\n\tarr[%d]:%d", i, arr[i]);
	}
	printf("\n");
	
	return 0;
}