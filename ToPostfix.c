#include <stdlib.h>
#include <ctype.h>	//int isdigit(int ch); ch�� ���޵� ������ ������ 10������� 1 ��ȯ
#include <string.h>	//void* memset(void* ptr, int val, size_t len); 
					//ptr�� ���޵� �ּ��� �޸𸮼����� len ����Ʈ�� val�� ������ ä���
#include "LStack.h"	//

//�������� �켱���� ������ ��ȯ�ϴ� �Լ� ����
int GetOpPrec(char op) {	
	switch (op) 
	{
		case '*' : 
		case '/' :
			return 3;	//���� ���� ���� �켱����
		case '+' :
		case '-' :
			return 2;	//�߰� ���� �켱����
		case '(' :
			return 1;	//���� ���� ���� �����
		//')'�� �ٸ� �����ڿ� �켱���� ���� �ʿ� �����Ƿ� ����
	}
	return -1;		//��ϵ��� ���� ������
}

//GetOpPrec�� ����� �������� �� �������� �켱������ ���Ͽ�, �� ����� ��ȯ�ϴ� �Լ� ����
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);	//�� �������� �켱���� ����
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)			//op1�� �켱������ �� ���� ���
		return 1;
	else if (op1Prec < op2Prec)		//op2�� �켱������ �� ���� ���
		return -1;
	else							//���� ���
		return 0;
}

//����ǥ������� ��ȯ�ϴ� �Լ� ����
void ConvToPost(char exp[]) {
	
	Stack stack;	//���� ����ü ����//
	
	int expLen = strlen(exp);			//����ǥ������� ǥ��� ���ڿ� ���� ���ϱ�
	char* convExp = (char*)malloc(expLen + 1);	//�� ���� ����Ͽ� ���ڿ� �����Ҵ�

	int i, idx = 0;		//���� ���� ����
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);	//�Ҵ�� �迭 ũ�⸸ŭ�� 0���� �ʱ�ȭ (string.h)

	StackInit(&stack);	//���� �ʱ�ȭ//

	for (i = 0; i < expLen; i++) {
		tok = exp[i];	//exp�� ���޵� ���� ���ڿ��� �� ���ھ� tok�� �ӽ� ����

		if (isdigit(tok)) {			//tok�� ����� ���ڰ� �������� Ȯ�� (ctype.h)
			convExp[idx++] = tok;	//1. ���ڿ� �ش��ϸ� �迭 convExp�� �ٷ� ����
		}
		else {						//2. ���ڰ� �ƴ� �����ڶ��, ������ �̿�
			switch (tok) {
				case '(' :				//���� �Ұ�ȣ�� �ش� �Ұ�ȣ�� ���ÿ� �ױ�
					SPush(&stack, tok);
					break;
				case ')' :				//�ݴ� �Ұ�ȣ�� ���ÿ� �ִ� �����ڵ� ������
					while (1) {
						popOp = SPop(&stack);

						if (popOp == '(')	//�� �ٸ� ���� �Ұ�ȣ�� ������ �ݺ� ����
							break;

						convExp[idx++] = popOp;	//������ �迭 convExp�� ����
					}
					break;
				case '+': case '-': 
				case '*': case '/':	//��Ģ������ ��� �켱���� ����� ���ÿ� �װų� ����
					//������ ���� �ʾҰ�, ���� �� ���� ������op1�� �� ������op2 �� op1�� �켱���� ���� ����,
					while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
						convExp[idx++] = SPop(&stack);		//���ÿ��� ������ ���� �迭 convExp�� ����
					
					//�� �������� op2�� �켱���� �� ���� �Ǹ�, ���ÿ� �ױ�
					SPush(&stack, tok);
					break;
			}
		}
	}

	while (!SIsEmpty(&stack))			//���ÿ� �����ִ� ��� �����ڸ�
		convExp[idx++] = SPop(&stack);	//�迭 convExp�� �̵�

	strcpy(exp, convExp);		//����ǥ������� ��ȯ�� ���� ���ڿ��� ���� �迭�� �����ϰ�
	free(convExp);				//���ڿ� ��ȯ�� ���� �����Ҵ��� ������ ����
}