#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i = 0, j = 0, q = 0, arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	
	printf("Enter the position = ");
	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		int x = arr[0];
		for (j = 0; j < 9; ++j)
			arr[j] = arr[j + 1];
		arr[9] = x;
	}

	printf("Result is= ");
	for (i = 0; i <= 9; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}