#include <stdio.h>
#include <stdlib.h>
#include "QueueA.h"	//

//ť �ʱ�ȭ �Լ�
void QueueInit(Queue* pq) {
	pq->front = 0;	//���� �ֺ� ���
	pq->rear = 0;	//�Ѵ� ���� �ε��� ����(���� ��ġ�� �ִٴ� ��)
}

//ť ������� Ȯ�� �Լ�
int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)	//ť�� �� ��� �� ��ȯ
		return TRUE;
	else						//�ƴ� ��� ���� ��ȯ
		return FALSE;
}

//ť�� ���� ��ġ�� �ش��ϴ� �ε��� �� ��ȯ�ϴ� �Լ�//
int NextPosIdx(int pos) {		
	if (pos == QUE_LEN - 1)		//�迭 ������ ����� �ε��� ���̶��
		return 0;					//������ �ٽ� �̵��ؾ� ��(ȸ��)
	else						//�ƴ� ���
		return pos + 1;				//���� ��ġ�� �̵�
}

//ť�� ������ �߰�
void Enqueue(Queue* pq, Data data) {
	//ť�� ���� ��� ���α׷� ����
	if (NextPosIdx(pq->rear) == pq->front) {	
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);	//R�� �� ĭ �������� �̵�
	pq->queArr[pq->rear] = data;		//�ش� ��ġ�� ������ ����
}

//ť�� ������ ����
Data Dequeue(Queue* pq) {
	//ť�� �� ��� ���α׷� ����
	if (QIsEmpty(pq)) {							
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);	//F�� �� ĭ �������� �̵�
	return pq->queArr[pq->front];		//������ ������ ��ȯ(������ ���� ���� ���ʿ� ������)
}

//ť�� ������ ��ȸ
Data QPeek(Queue* pq) {
	//ť�� �� ��� ���α׷� ����
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];	//���� �ε����� �ش� ������ ��ȯ(�ε��� �̵��� ����)
}