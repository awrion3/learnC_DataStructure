#ifndef __QUEUE_A_H__
#define __QUEUE_A_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100		//큐 길이

typedef int Data;

typedef struct CQueue {	//원형 큐 관련 구현
	int front;	//F 변수
	int rear;	//R 변수
	Data queArr[QUE_LEN];	//원형 큐
} CQueue;

typedef CQueue Queue;	//사용자 형 정의

//함수 원형 선언
void QueueInit(Queue* pq);	//큐 초기화
int QIsEmpty(Queue* pq);	//큐 비웠는지 확인

void Enqueue(Queue* pq, Data data);	//큐 넣기
Data Dequeue(Queue* pq);			//큐 빼기

Data QPeek(Queue* pq);				//큐 확인
#endif