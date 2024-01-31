#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"	//

//1 �� �ʱ�ȭ �Լ� ����
void DequeInit(Deque* pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

//2 �� �� ���� Ȯ�� �Լ� ����
int DQIsEmpty(Deque* pdeq) {
	if (pdeq->head == NULL)	//head�� NULL�̸� �� ��
		return TRUE;
	else
		return FALSE;
}

//3 �� �Ӹ��� ������ ���� �Լ� ����
void DQAddFirst(Deque* pdeq, Data data) {
	//�� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;			//������ �� ��忡 ����
	newNode->next = pdeq->head;		//�� ����� ������ ������ �� �� ���� ����

	if (DQIsEmpty(pdeq))			//���� �� ���
		pdeq->tail = newNode;			//������ �� ��带 ����Ű�� ��
	else							//���� ���� ���
		pdeq->head->prev = newNode;		//���� �� �� ����� ������ �� ���� ����(�����)

	newNode->prev = NULL;			//�� ����� ������ �ΰ� ����
	pdeq->head = newNode;			//�Ӹ��� �� ��带 ����Ű�� ��
}

//4 �� ������ ������ ���� �Լ� ����
void DQAddLast(Deque* pdeq, Data data) {
	//�� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;			//������ �� ��忡 ����
	newNode->prev = pdeq->tail;		//�� ����� ������ ������ �� �� ���� ����

	if (DQIsEmpty(pdeq))			//���� �� ���
		pdeq->head = newNode;			//�Ӹ��� �� ��带 ����Ű�� ��
	else							//���� ���� ���
		pdeq->tail->next = newNode;		//���� �� �� ����� ������ �� ���� ����(�����)

	newNode->next = NULL;			//�� ����� ������ �ΰ� ����
	pdeq->tail = newNode;			//������ �� ��带 ����Ű�� ��
}

//5 �� �Ӹ��� ������ ���� �Լ� ����
Data DQRemoveFirst(Deque* pdeq) {
	Node* rnode = pdeq->head;	//���� ������ �Ӹ��� ��� ����Ű��
	Data rdata;					//���� ������ �Ӹ��� ��� �����͸� ���� ���� ����

	if (DQIsEmpty(pdeq)) {		//�� ���� ��� ���α׷� ����
		printf("Deque Memory Error!");
		exit(-1);
	}

	rdata = pdeq->head->data;		//�Ӹ� ����� ������ �ӽ� ����
	pdeq->head = pdeq->head->next;	//�Ӹ� ��带 ������ ���� ����

	free(rnode);				//�Ӹ� ����� ������ ����

	if (pdeq->head == NULL)		//�Ӹ� ��尡 NULL�̸� ���� ��嵵 ����
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL; //�� �Ӹ� ����� ������ NULL�� ����(�����)

	return rdata;	//�ӽ� ����� ���� ����� ������ ��ȯ
}

//6 �� ������ ������ ���� �Լ� ����
Data DQRemoveLast(Deque* pdeq) {
	Node* rnode = pdeq->tail;	//���� ������ ������ ��� ����Ű��
	Data rdata;					//���� ������ ������ ��� �����͸� ���� ���� ����

	if (DQIsEmpty(pdeq)) {		//�� ���� ��� ���α׷� ����
		printf("Deque Memory Error!");
		exit(-1);
	}

	rdata = pdeq->tail->data;		//���� ����� ������ �ӽ� ����
	pdeq->tail = pdeq->tail->prev;	//���� ��带 ������ ���� ����

	free(rnode);				//���� ����� ������ ����

	if (pdeq->tail == NULL)		//���� ��尡 NULL�̸� �Ӹ� ��嵵 ����
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL; //�� ���� ����� ������ NULL�� ����(�����)

	return rdata;	//�ӽ� ����� ���� ����� ������ ��ȯ
}

//7 �� �Ӹ��� ������ ��ȸ �Լ� ����
Data DQGetFirst(Deque* pdeq) {
	
	if (DQIsEmpty(pdeq)) {		//�� ���� ��� ���α׷� ����
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;	//�Ӹ� ����� ������ ��ȯ
}

//8 �� ������ ������ ��ȸ �Լ� ����
Data DQGetLast(Deque* pdeq) {

	if (DQIsEmpty(pdeq)) {		//�� ���� ��� ���α׷� ����
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;	//���� ����� ������ ��ȯ
}