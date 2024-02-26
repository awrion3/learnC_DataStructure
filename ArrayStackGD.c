#include <stdio.h>
#include <stdlib.h>
#include "ArrayStackGD.h"	//

//1 ���� �ʱ�ȭ �Լ� ����
void StackInit(Stack* pstack) {
	pstack->topIndex = -1;	//�ε��� -1 == ���ÿ� �ƹ��͵� ���� ����
}

//2 ������ ���� ���� Ȯ�� �Լ� ����
int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)	//������ �� ��� 1 ��ȯ
		return TRUE;
	else						//�׷��� ������ 0 ��ȯ
		return FALSE;
}

//3 ���� �ֱ� �Լ� ����
void SPush(Stack* pstack, Data data) {
	pstack->topIndex++;							//���� �ε��� �̵� ��
	pstack->stackArr[pstack->topIndex] = data;	//���� ����ü�� ����� ������ �ش� ������ ������ ������ ����
}

//4 ���� ����(����) �Լ� ����
Data SPop(Stack* pstack) {
	int rIdx;					//�ε��� �����ϱ� ���� ���� ����

	if (SIsEmpty(pstack)) {				//������ �� ���
		printf("Stack Memory Error!");
		exit(-1);	//return�� �Լ� ����, exit�� �Լ� ������� ���α׷� ����
	}

	rIdx = pstack->topIndex;	//���� ������(== ���������� ���� ������)�� ���� �ε��� ����
	pstack->topIndex--;			//��ü ������ �� �ϳ� ����(== ���� ������ ����)

	return pstack->stackArr[rIdx];		//������ ������ ������ ��ȯ(== ���� ������)
}

//5 ������ ������ Ȯ�� �Լ� ����
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {				//������ �� ��� ���α׷� ����
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];	//SPop�� ����+��ȯ�̸�, SPeek�� ������ ������ ��ȯ��
}