#ifndef __ARRAY_STACK_K_H__
#define __ARRAY_STACK_K_H__

#define TRUE 1
#define FALSE 0

#define STACK_LEN 100	//스택 크기

//구조체 정의 및 형 정의
typedef int Data;

typedef struct arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

//함수 원형 선언
void StackInit(Stack* pstack);	//스택의 초기화

int SIsEmpty(Stack* pstack);	//스택이 비었는지 확인

void SPush(Stack* pstack, Data data);	//스택에 데이터 넣기
Data SPop(Stack* pstack);				//스택에 데이터 빼기

Data SPeek(Stack* pstack);		//마지막 스택 데이터 확인
#endif#

