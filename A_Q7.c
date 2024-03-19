#pragma warning(disable:4996)
#include <stdio.h>

int isprime(int n) {
	int isp = 1;

	if (n < 2)
		return 0;
	else {
		for (int i = 2; i < n; i++)
			if (n % i == 0) {
				isp = 0;
				break;
			}
	}

	return isp;
}

int main(void) {

	int num, arr[100];

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < num; i++)
		if (isprime(arr[i]) == 0)
			printf("%d ", arr[i]);
			
	return 0;
}