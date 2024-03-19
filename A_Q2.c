#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int arr[5], max;

	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	max = arr[0];

	for (int i = 1; i < 5; i++)
		if (max < arr[i])
			max = arr[i];

	printf("%d", max);

	return 0;
}