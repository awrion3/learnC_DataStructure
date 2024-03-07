#pragma warning(disable:4996)
#include <stdio.h>
//7
//Write a C program to check whether a number can be expressed as the sum of two prime numbers.//

int checkHalfPrime(int n) {
    int i, isp = 1;

    if (n == 0 || n == 1) {
        isp = 0;
    }
    else {
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isp = 0;
                break;
            }
        }
    }

    return isp;
}

int main(void) {

	int n, flag = 0;
	scanf("%d", &n);

    for (int i = 2; i <= n / 2; i++) {
       if (checkHalfPrime(i) == 1) {
            if (checkHalfPrime(n - i) == 1) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        }
    }

    if (flag == 0)
        printf("%d can't be expressed as the sum of two prime numbers.", n);
    else
        printf("%d can be expressed as the sum of two prime numbers.", n);

	return 0;
}