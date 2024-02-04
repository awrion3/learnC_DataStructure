#ifndef __STACK_BT_H__
#define __STACK_BT_H__
//�� ��带 �Ӹ��� �߰��ϴ� ����� ���� ����Ʈ ���
#include "BTreeT.h"			//�Ʒ� �� ���� �����Ͽ� �߰�//

#define TRUE 1
#define FALSE 0

//�� ����
typedef BTreeNode* Data;	//���� Ʈ�� �����Ͽ� ���ÿ� ����Ǵ� ��� int���� node �����ͷ� ����//

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

Data SPeek(Stack* pstack);		//������ ������ Ȯ��
#endif