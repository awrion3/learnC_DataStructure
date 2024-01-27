#ifndef __STACK_L_H__
#define __STACK_L_H__
//새 노드를 머리에 추가하는 방식의 연결 리스트 사용

#define TRUE 1
#define FALSE 0

//형 정의
typedef int Data;

//연결 리스트 구성 노드 구조체 정의
typedef struct node {
	Data data;
	struct node* next;
} Node;

//연결 리스트 기반 스택 구조체 정의
typedef struct listStack {
	Node* head;
} ListStack;

typedef ListStack Stack;

//함수 원형 선언
void StackInit(Stack* pstack);	//스택 초기화

int SIsEmpty(Stack* pstack);	//스택 비었는지 확인

void SPush(Stack* pstack, Data data);	//스택 넣기
Data SPop(Stack* pstack);				//스택 빼기

Data Speek(Stack* pstack);		//마지막 데이터 확인
#endif