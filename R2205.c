#pragma warning(disable:4996)
#include <stdio.h>
//5
//Write a C program to reverse a number.

int main(void) {

	int n, a, r = 0;
	scanf("%d", &n);

	while (n > 0) {
		r *= 10;
		a = n % 10;
		r += a;
		n /= 10;
	}

	printf("%d", r);

	return 0;
}