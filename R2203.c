#pragma warning(disable:4996)
#include <stdio.h>
//3
//Write a C program to check leap year.

int main(void) {

	int y;
	scanf("%d", &y);

	if (!(y % 4) && (y % 100) || !(y % 400))
		printf("%d year is leap year\n", y);
	else
		printf("%d year is not leap year\n", y);

	return 0;
}