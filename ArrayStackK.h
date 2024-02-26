#ifndef __ARRAY_STACK_K_H__
#define __ARRAY_STACK_K_H__

#define TRUE 1
#define FALSE 0

#define STACK_LEN 100	//���� ũ��

//����ü ���� �� �� ����
typedef int Data;

typedef struct arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

//�Լ� ���� ����
void StackInit(Stack* pstack);	//������ �ʱ�ȭ

int SIsEmpty(Stack* pstack);	//������ ������� Ȯ��

void SPush(Stack* pstack, Data data);	//���ÿ� ������ �ֱ�
Data SPop(Stack* pstack);				//���ÿ� ������ ����

Data SPeek(Stack* pstack);		//������ ���� ������ Ȯ��
#endif#

