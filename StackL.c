#include <stdio.h>
#include <stdlib.h>
#include "StackL.h"	//

//���� �ʱ�ȭ �Լ� ����
void StackInit(Stack* pstack) {
	pstack->head = NULL;	//������ head�� NULL�� �ʱ�ȭ�Ѵ�
}

//���� ������� Ȯ�� �Լ� ����
int SIsEmpty(Stack* pstack) {
	//������ head�� NULL�� ����Ű�� ������ ������Ƿ� 1�� ��ȯ
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

//���� �ֱ� �Լ� ����
void SPush(Stack* pstack, Data data) {
	//�� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;			//�� ��忡 ������ ����
	newNode->next = pstack->head;	//�� ��� ������ �ֱٿ� �߰��� ���� ����

	//������ head�� �� ��带 ����Ű�� ��
	pstack->head = newNode;
}

//���� ���� �Լ� ����
Data SPop(Stack* pstack) {
	//���� ����
	Data rdata;
	Node* rnode;
	
	if (SIsEmpty(pstack)) {		//������ �� ��� ���α׷� ����
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;		//������ ����� �����͸� ����
	rnode = pstack->head;			//������ ����� �ּҰ��� ����

	//������ ����� ���� ��带 ������ head�� ����Ű�� ����
	pstack->head = pstack->head->next;
	free(rnode);		//��� ����

	return rdata;		//������ ����� ������ ��ȯ
}

//���� ������ ������ Ȯ�� �Լ� ����
Data SPeek(Stack* pstack) {

	if (SIsEmpty(pstack)) {		//������ �� ��� ���α׷� ����
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;	//head�� ����Ű�� ��忡 ����� ������ ��ȯ
}