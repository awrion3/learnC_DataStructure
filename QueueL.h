#ifndef __QUEUE_LIST_H__
#define __QUEUE_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {		//연결 리스트 기반
	Data data;
	struct node* next;
} Node;

typedef struct LQueue {		//큐 구현
	Node* front;	//F 변수
	Node* rear;		//R 변수
} LQueue;

typedef LQueue Queue;

//함수 원형 선언
void QueueInit(Queue* pq);	//큐 초기화
int QIsEmpty(Queue* pq);	//큐 비움 확인

void Enqueue(Queue* pq, Data data);	//큐 넣기
Data Dequeue(Queue* pq);			//큐 빼기
Data QPeek(Queue* pq);				//큐 확인
#endif