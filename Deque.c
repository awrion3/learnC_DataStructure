#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"	//

//1 덱 초기화 함수 정의
void DequeInit(Deque* pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

//2 덱 빈 상태 확인 함수 정의
int DQIsEmpty(Deque* pdeq) {
	if (pdeq->head == NULL)	//head가 NULL이면 빈 덱
		return TRUE;
	else
		return FALSE;
}

//3 덱 머리에 데이터 저장 함수 정의
void DQAddFirst(Deque* pdeq, Data data) {
	//새 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;			//데이터 새 노드에 저장
	newNode->next = pdeq->head;		//새 노드의 다음을 기존의 맨 앞 노드와 연결

	if (DQIsEmpty(pdeq))			//덱이 빈 경우
		pdeq->tail = newNode;			//꼬리가 새 노드를 가리키게 함
	else							//비지 않은 경우
		pdeq->head->prev = newNode;		//기존 맨 앞 노드의 이전을 새 노드와 연결(양방향)

	newNode->prev = NULL;			//새 노드의 이전은 널과 연결
	pdeq->head = newNode;			//머리가 새 노드를 가리키케 함
}

//4 덱 꼬리에 데이터 저장 함수 정의
void DQAddLast(Deque* pdeq, Data data) {
	//새 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;			//데이터 새 노드에 저장
	newNode->prev = pdeq->tail;		//새 노드의 이전을 기존의 맨 뒤 노드와 연결

	if (DQIsEmpty(pdeq))			//덱이 빈 경우
		pdeq->head = newNode;			//머리가 새 노드를 가리키게 함
	else							//비지 않은 경우
		pdeq->tail->next = newNode;		//기존 맨 뒤 노드의 다음을 새 노드와 연결(양방향)

	newNode->next = NULL;			//새 노드의 다음은 널과 연결
	pdeq->tail = newNode;			//꼬리가 새 노드를 가리키케 함
}

//5 덱 머리의 데이터 삭제 함수 정의
Data DQRemoveFirst(Deque* pdeq) {
	Node* rnode = pdeq->head;	//덱의 삭제할 머리의 노드 가리키기
	Data rdata;					//덱의 삭제할 머리의 노드 데이터를 위한 저장 공간

	if (DQIsEmpty(pdeq)) {		//빈 덱인 경우 프로그램 종료
		printf("Deque Memory Error!");
		exit(-1);
	}

	rdata = pdeq->head->data;		//머리 노드의 데이터 임시 저장
	pdeq->head = pdeq->head->next;	//머리 노드를 다음의 노드로 갱신

	free(rnode);				//머리 노드의 데이터 삭제

	if (pdeq->head == NULL)		//머리 노드가 NULL이면 꼬리 노드도 갱신
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL; //새 머리 노드의 이전을 NULL로 정정(양방향)

	return rdata;	//임시 저장된 삭제 노드의 데이터 반환
}

//6 덱 꼬리의 데이터 삭제 함수 정의
Data DQRemoveLast(Deque* pdeq) {
	Node* rnode = pdeq->tail;	//덱의 삭제할 꼬리의 노드 가리키기
	Data rdata;					//덱의 삭제할 꼬리의 노드 데이터를 위한 저장 공간

	if (DQIsEmpty(pdeq)) {		//빈 덱인 경우 프로그램 종료
		printf("Deque Memory Error!");
		exit(-1);
	}

	rdata = pdeq->tail->data;		//꼬리 노드의 데이터 임시 저장
	pdeq->tail = pdeq->tail->prev;	//꼬리 노드를 이전의 노드로 갱신

	free(rnode);				//꼬리 노드의 데이터 삭제

	if (pdeq->tail == NULL)		//꼬리 노드가 NULL이면 머리 노드도 갱신
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL; //새 꼬리 노드의 다음을 NULL로 정정(양방향)

	return rdata;	//임시 저장된 삭제 노드의 데이터 반환
}

//7 덱 머리에 데이터 조회 함수 정의
Data DQGetFirst(Deque* pdeq) {
	
	if (DQIsEmpty(pdeq)) {		//빈 덱인 경우 프로그램 종료
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;	//머리 노드의 데이터 반환
}

//8 덱 꼬리에 데이터 조회 함수 정의
Data DQGetLast(Deque* pdeq) {

	if (DQIsEmpty(pdeq)) {		//빈 덱인 경우 프로그램 종료
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;	//꼬리 노드의 데이터 반환
}