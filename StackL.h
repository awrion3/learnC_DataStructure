#ifndef __STACK_L_H__
#define __STACK_L_H__
//�� ��带 �Ӹ��� �߰��ϴ� ����� ���� ����Ʈ ���

#define TRUE 1
#define FALSE 0

//�� ����
typedef int Data;

//���� ����Ʈ ���� ��� ����ü ����
typedef struct node {
	Data data;
	struct node* next;
} Node;

//���� ����Ʈ ��� ���� ����ü ����
typedef struct listStack {
	Node* head;
} ListStack;

typedef ListStack Stack;

//�Լ� ���� ����
void StackInit(Stack* pstack);	//���� �ʱ�ȭ

int SIsEmpty(Stack* pstack);	//���� ������� Ȯ��

void SPush(Stack* pstack, Data data);	//���� �ֱ�
Data SPop(Stack* pstack);				//���� ����

Data Speek(Stack* pstack);		//������ ������ Ȯ��
#endif