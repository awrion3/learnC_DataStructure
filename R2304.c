#pragma warning(disable:4996)
#include <stdio.h>
//4
//Write a C program to return a pointer from a function in c.

int* idxSearchAddr(int *p, int id, int l) {
	int *valloc = NULL;

	for (int i = 0; i < l; i++) {
		if (id == i) {
			valloc = p + i;
			break;
		}
	}

	return valloc;
}

int main(void) {

	int arr[5] = { 1, 2, 3, 4, 5 };
	int idx, *loc;

	printf("input index: ");
	scanf("%d", &idx);

	loc = idxSearchAddr(arr, idx, 5);
	
	if (loc == NULL)
		printf("error: id out of range\n");
	else
		printf("%d", *loc);

	return 0;
}