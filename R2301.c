#pragma warning(disable:4996)
#include <stdio.h>
//1
//Write a C program to merge two arrays.

int main(void) {

	int arr[3] = { 1, 2, 3 }, brr[3] = { 4, 5, 6 };
	int crr[3] = { 0 };

	for (int i = 0; i < 3; i++){
		crr[i] = arr[i] + brr[i];
		printf("%d ", crr[i]);
	}

	return 0;
}