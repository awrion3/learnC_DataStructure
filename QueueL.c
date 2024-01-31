#include <stdio.h>
#include <stdlib.h>
#include "QueueL.h"	//

//1 ť �ʱ�ȭ�ϴ� �Լ� ����
void QueueInit(Queue* pq) {
	pq->front = NULL;	//F ����
	pq->rear = NULL;	//R ����
}

//2 ť�� ������� Ȯ���ϴ� �Լ� ����
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)	//F�� NULL�� ����Ǿ� ������ �� ť�̹Ƿ� 1 ��ȯ
		return TRUE;
	else					//�ƴϸ� 0 ��ȯ
		return FALSE;
}

//3 ť�� �����͸� �ִ� �Լ� ����
void Enqueue(Queue* pq, Data data) {
	//�� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	//����� ������ ���� ���ϰ�, ��忡 ������ ����
	newNode->next = NULL;
	newNode->data = data;
	
	if (QIsEmpty(pq)) {				//ù ����� �߰����
		pq->front = newNode;			//F�� �� ��带 ����Ű�� �ϰ�,
		pq->rear = newNode;				//R�� �� ��带 ����Ű�� �Ѵ�
	}
	else {							//�� ��° ���� ����� �߰����
		pq->front->next = newNode;		//������ ������ ��尡 �� ��带 ����Ű�� �Ѵ�
		pq->rear = newNode;				//R�� �� ��带 ����Ű�� �Ѵ�
	}
}

//4 ť�� �����͸� ���� �Լ� ����
Data Dequeue(Queue* pq) {
	//���� ����
	Node* delNode;
	Data retData;

	//ť�� �� ��� ���α׷� ����
	if (QIsEmpyt(pq)) {	
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;			//������ ����� �ּҰ� ����
	retData = delNode->data;		//������ ����� ������ ����
	pq->front = pq->front->next;	//������ ����� ���� ��带 front�� ����Ű�� ����
	//������ ť�� ������ rear�� �����Ⱚ�� ����Ű�µ�, QIsEmpty���� R�� ������ �����Ƿ� ������� 

	free(delNode);		//��� ����
	return retData;		//������ ����� ������ ��ȯ
}

//5 ť�� �����͸� Ȯ���ϴ� �Լ� ����
Data QPeek(Queue* pq) {
	//ť�� �� ��� ���α׷� ����
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	//�� ���� ť�� ������ ��ȯ
	return pq->front->data;	
}