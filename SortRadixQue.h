#ifndef __SORT_RADIX_QUE_H__
#define __SORT_RADIX_QUE_H__	//���� ����Ʈ ����� ť Ȱ��

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {		//���� ����Ʈ ���
	Data data;
	struct node* next;
} Node;

typedef struct LQueue {		//ť ����
	Node* front;	//F ����
	Node* rear;		//R ����
} LQueue;

typedef LQueue Queue;

//�Լ� ���� ����
void QueueInit(Queue* pq);	//ť �ʱ�ȭ
int QIsEmpty(Queue* pq);	//ť ��� Ȯ��

void Enqueue(Queue* pq, Data data);	//ť �ֱ�
Data Dequeue(Queue* pq);			//ť ����
Data QPeek(Queue* pq);				//ť Ȯ��
#endif