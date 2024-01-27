#include <stdio.h>
#include <stdlib.h>
#include "StackL.h"	//

//스택 초기화 함수 정의
void StackInit(Stack* pstack) {
	pstack->head = NULL;	//포인터 head는 NULL로 초기화한다
}

//스택 비었는지 확인 함수 정의
int SIsEmpty(Stack* pstack) {
	//포인터 head가 NULL을 가리키고 있으면 비었으므로 1을 반환
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

//스택 넣기 함수 정의
void SPush(Stack* pstack, Data data) {
	//새 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;			//새 노드에 데이터 저장
	newNode->next = pstack->head;	//새 노드 다음을 최근에 추가된 노드와 연결

	//포인터 head가 새 노드를 가리키게 함
	pstack->head = newNode;
}

//스택 빼기 함수 정의
Data SPop(Stack* pstack) {
	//변수 선언
	Data rdata;
	Node* rnode;
	
	if (SIsEmpty(pstack)) {		//스택이 빈 경우 프로그램 종료
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;		//삭제할 노드의 데이터를 저장
	rnode = pstack->head;			//삭제할 노드의 주소값을 저장

	//삭제할 노드의 다음 노드를 포인터 head가 가리키게 갱신
	pstack->head = pstack->head->next;
	free(rnode);		//노드 삭제

	return rdata;		//삭제된 노드의 데이터 반환
}

//스택 마지막 데이터 확인 함수 정의
Data SPeek(Stack* pstack) {

	if (SIsEmpty(pstack)) {		//스택이 빈 경우 프로그램 종료
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;	//head가 가리키는 노드에 저장된 데이터 반환
}