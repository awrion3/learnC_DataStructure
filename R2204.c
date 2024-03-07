#pragma warning(disable:4996)
#include <stdio.h>
//4
//Write a C program to print the Fibonacci series.

int fib(int n) {

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(void) {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%dth fib number is %d\n", i + 1, fib(i));
	}

	return 0;
}