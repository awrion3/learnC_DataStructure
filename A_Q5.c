#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int num, arr[100], min, max;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	min = arr[0];
	max = arr[0];

	for (int i = 0; i < num; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	printf("%d %d", max, min);

	return 0;
}