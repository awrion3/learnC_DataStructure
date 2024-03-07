#pragma warning(disable:4996)
#include <stdio.h>
//1
//Write a C program to add two complex numbers.

typedef struct complex {
	int real;
	double imag;
} complex;

int main(void) {

	complex a, b, c;

	scanf("%d %lf", &a.real, &a.imag);
	scanf("%d %lf", &b.real, &b.imag);

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	printf("%.2f", c.real + c.imag);

	return 0;
}