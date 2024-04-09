#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char exp1[100], exp2[100];
	char *p, *q;

	scanf("%s", exp1);
	scanf("%s", exp2);

	for (p = exp1, q = exp2; p < exp1 + strlen(exp1); p++, q++) {
		if (*p != *q) {
			printf("%d", 1);
		}
		else
			printf("%d", 0);
	}

	return 0;
}