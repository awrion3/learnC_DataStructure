#pragma warning(disable:4996)
#include <stdio.h>
//2
//Write a C program to multiply two matrices.

int main(void) {

	int arr[2][2] = { 0, 1, 2, 3 };
	int brr[2][2] = { 1, 2, 3, 0 };
	int crr[2][2] = { 0 };

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++) {
			crr[i][j] = arr[i][j] + brr[i][j];
			printf("%d ", crr[i][j]);
		}
		printf("\n");
	}

	return 0;
}