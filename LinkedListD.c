#include <stdio.h>
#include <stdlib.h>
#include "LinkedListD.h"

//리스트 초기화 함수 정의
void ListInit(List* plist) {
	plist->head = NULL;		//양방향 연결 리스트이므로 plist->before는 불필요
	plist->numOfData = 0;
}

//노드 삽입 함수 정의
void LInsert(List* plist, Data data) {
	//새 노드 생성 및 데이터 저장
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	//첫 노드인 경우: 새 노드의 다음을 NULL로 초기화 
	//두번째 이후 노드인 경우: 새 노드의 다음을 기존 노드로 초기화
	newNode->next = plist->head;

	if (plist->head != NULL)			//첫번째 노드 추가가 아닌 경우,
		plist->head->prev = newNode;	//기존 노드의 이전을 새 노드로 지정(양방향 연결)

	//새 노드의 이전을 NULL로 초기화
	newNode->prev = NULL;
	//포인터 head가 새 노드를 가리키게 갱신
	plist->head = newNode;

	plist->numOfData++;	//전체 데이터 수 하나 증가
}

//리스트 조회 함수 정의
int LFirst(List* plist, Data* pdata) {		//첫 번째 노드 데이터 조회
	if (plist->head == NULL)	//노드가 없는 경우 FALSE 반환
		return FALSE;

	plist->cur = plist->head;	//cur이 첫 노드를 가리키게 함
	
	*pdata = plist->cur->data;	//데이터 반환 성공
	return TRUE;
}

int LNext(List* plist, Data* pdata) {		//두 번째 이후의 노드 데이터 조회
	if (plist->cur->next == NULL)	//다음 노드가 없는 경우 FALSE 반환
		return FALSE;

	plist->cur = plist->cur->next;	//cur이 다음 노드를 가리키게 함

	*pdata = plist->cur->data;		//데이터 반환 성공
	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {	//LNext의 반대 방향으로 데이터 조회
	if (plist->cur->prev == NULL)	//이전 노드가 없는 경우 FALSE 반환
		return FALSE;

	plist->cur = plist->cur->prev;	//cur이 이전 노드를 가리키게 함

	*pdata = plist->cur->data;		//데이터 반환 성공
	return TRUE;
}

//데이터 수 확인 함수 정의
int LCount(List* plist) {
	return plist->numOfData;	//전체 데이터 수 반환
}