#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int arr[100], num, kth, cut = 0, adv = 0;
	int *p, *q, tmp;

	scanf("%d %d", &num, &kth);

	for (p = arr; p < arr + num; p++) {
		scanf("%d", p);
	}

	for (p = arr; p < arr + num - 1; p++) {
		for (q = arr; q < arr + num - 1; q++) {
			if (*q < *(q + 1)) {
				tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
		}
	}

	cut = *(arr + kth - 1);

	for (p = arr; p < arr + num; p++) {
		if (*p >= cut && *p > 0) {
			adv += 1;
		}
	}

	printf("%d", adv);

	return 0;
}