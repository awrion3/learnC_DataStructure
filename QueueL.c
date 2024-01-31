#include <stdio.h>
#include <stdlib.h>
#include "QueueL.h"	//

//1 큐 초기화하는 함수 정의
void QueueInit(Queue* pq) {
	pq->front = NULL;	//F 변수
	pq->rear = NULL;	//R 변수
}

//2 큐가 비었는지 확인하는 함수 정의
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)	//F에 NULL이 저장되어 있으면 빈 큐이므로 1 반환
		return TRUE;
	else					//아니면 0 반환
		return FALSE;
}

//3 큐에 데이터를 넣는 함수 정의
void Enqueue(Queue* pq, Data data) {
	//새 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	//노드의 다음을 연결 안하고, 노드에 데이터 저장
	newNode->next = NULL;
	newNode->data = data;
	
	if (QIsEmpty(pq)) {				//첫 노드의 추가라면
		pq->front = newNode;			//F가 새 노드를 가리키게 하고,
		pq->rear = newNode;				//R이 새 노드를 가리키게 한다
	}
	else {							//두 번째 이후 노드의 추가라면
		pq->front->next = newNode;		//기존의 마지막 노드가 새 노드를 가리키게 한다
		pq->rear = newNode;				//R이 새 노드를 가리키게 한다
	}
}

//4 큐에 데이터를 빼는 함수 정의
Data Dequeue(Queue* pq) {
	//변수 선언
	Node* delNode;
	Data retData;

	//큐가 빈 경우 프로그램 종료
	if (QIsEmpyt(pq)) {	
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;			//삭제할 노드의 주소값 저장
	retData = delNode->data;		//삭제할 노드의 데이터 저장
	pq->front = pq->front->next;	//삭제할 노드의 다음 노드를 front가 가리키게 갱신
	//마지막 큐를 삭제시 rear는 쓰레기값을 가리키는데, QIsEmpty에서 R은 쓰이지 않으므로 상관없음 

	free(delNode);		//노드 삭제
	return retData;		//삭제된 노드의 데이터 반환
}

//5 큐의 데이터를 확인하는 함수 정의
Data QPeek(Queue* pq) {
	//큐가 빈 경우 프로그램 종료
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	//맨 앞의 큐의 데이터 반환
	return pq->front->data;	
}