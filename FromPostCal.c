#include <string.h>
#include <ctype.h>
#include "LStack.h"	//

int PostCal(char exp[]) {
	
	Stack stack;
	int expLen = strlen(exp);	//���� ���ڿ� ���� ���ϱ�
	char tok, op1, op2;

	StackInit(&stack);	//���� �ʱ�ȭ

	for (int i = 0; i < expLen; i++) {	//������ �����ϴ� ���� ������ ������� �ݺ�
		tok = exp[i];	//�� ���ھ� tok�� ����

		if (isdigit(tok)) {				//���ڰ� �������
			SPush(&stack, tok - '0');	//���ڷ� ��ȯ�Ͽ� ���ÿ� �ֱ�
		}
		else {							//���ڰ� �����ڶ��
			op2 = SPop(&stack);			//���ÿ��� ���ڸ� �����µ�, �ι�° �ǿ����ڷ� ����
			op1 = SPop(&stack);			//..., ù��° �ǿ����ڷ� ����

			switch (tok) {				//�ش� �����ڰ� �������� �ľ��� �� �ǿ����ڸ� �����ϱ�
			case '+':
				SPush(&stack, op1 + op2);	//������ ��� ���ÿ� �ٽ� �ֱ�
				break;
			case '-':
				SPush(&stack, op1 - op2);	//...
				break;
			case '*':
				SPush(&stack, op1 * op2);	//...
				break;
			case '/':
				SPush(&stack, op1 / op2);	//...
				break;
			}
		}
	}
	return SPop(&stack);	//���� ���� ����� ���ÿ��� ������ ��ȯ
}