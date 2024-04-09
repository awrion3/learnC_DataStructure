#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	
	int arr[100], num, *p, *q, tmp, dup;

	scanf("%d", &num);

	for (p = arr; p < arr + num; p++) {
		scanf("%d", p);
	}

	for (p = arr; p < arr + num - 1; p++) {
		for (q = arr; q < arr + num - 1; q++) {
			if (*q > *(q + 1)) {
				tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
		}
	}

	for (p = arr; p < arr + num; p++) {
		dup = 0;
		for (q = arr; q < p; q++) {
			if (*p == *q) {
				dup = 1;
			}
		}
		if (dup == 0)
			printf("%d ", *p);
	}

	return 0;
}