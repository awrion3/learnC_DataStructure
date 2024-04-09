#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int ans[5][5] = { 0 };
	int arr[5][5] = { 0 };
	int x = 0, y = 0, *px = &x, *py = &y;

	ans[2][2] = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", *(arr + i) + j);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (*(*(arr + i) + j) == 1) {
				*px = i, *py = j;
			}
		}
	}

	*px = *px - 2 < 0 ? -(*px - 2) : *px - 2;
	*py = *py - 2 < 0 ? -(*py - 2) : *py - 2;

	printf("%d", *px + *py);

	return 0;
}
/*
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/