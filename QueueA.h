#ifndef __QUEUE_A_H__
#define __QUEUE_A_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100		//ť ����

typedef int Data;

typedef struct CQueue {	//���� ť ���� ����
	int front;	//F ����
	int rear;	//R ����
	Data queArr[QUE_LEN];	//���� ť
} CQueue;

typedef CQueue Queue;	//����� �� ����

//�Լ� ���� ����
void QueueInit(Queue* pq);	//ť �ʱ�ȭ
int QIsEmpty(Queue* pq);	//ť ������� Ȯ��

void Enqueue(Queue* pq, Data data);	//ť �ֱ�
Data Dequeue(Queue* pq);			//ť ����

Data QPeek(Queue* pq);				//ť Ȯ��
#endif