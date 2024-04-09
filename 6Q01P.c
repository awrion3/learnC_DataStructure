#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char exp[100];
	int op1 = 0, op2 = 0, fl = 0, res = 0, *rp = &res;
	char opr;

	scanf("%s", exp);

	for (int i = 0; i < strlen(exp); i++) {
		if (*(exp + i) >= '0' && *(exp + i) <= '9') {
			if (fl == 0) {
				op1 *= 10;
				op1 += (*(exp + i) - '0');
			}
			else {
				op2 *= 10;
				op2 += (*(exp + i) - '0');
			}
		}
		else {
			opr = *(exp + i);
			fl = 1;
		}			
	}

	fl = 0;
	switch (opr) {
	case '*':
		*rp = op1 * op2;
		break;
	case '/':
		if (op2 == 0)
			fl = 1;
		else
			*rp = op1 / op2;
		break;
	case '-':
		*rp = op1 - op2;
		break;
	case '+':
		*rp = op1 + op2;
		break;
	}

	if (fl == 0)
		printf("%d", *rp);
	else
		printf("error");

	return 0;
}