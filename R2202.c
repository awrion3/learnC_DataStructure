#pragma warning(disable:4996)
#include <stdio.h>
//2
//Write a C program to print prime numbers from 1 to n.

int main(void) {
	
	int n, isp;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		isp = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0)
				isp = 0;
		}
		if (isp == 1 && i != 1)
			printf("%d ", i);
	}

	return 0;
}