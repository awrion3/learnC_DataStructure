#include <stdio.h>
#include <stdlib.h>
#include "ArrayStackGD.h"	//

//1 스택 초기화 함수 정의
void StackInit(Stack* pstack) {
	pstack->topIndex = -1;	//인덱스 -1 == 스택에 아무것도 없는 상태
}

//2 데이터 존재 여부 확인 함수 정의
int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)	//스택이 빈 경우 1 반환
		return TRUE;
	else						//그렇지 않으면 0 반환
		return FALSE;
}

//3 스택 넣기 함수 정의
void SPush(Stack* pstack, Data data) {
	pstack->topIndex++;							//스택 인덱스 이동 후
	pstack->stackArr[pstack->topIndex] = data;	//스택 구조체의 멤버인 스택의 해당 공간에 접근해 데이터 저장
}

//4 스택 빼기(삭제) 함수 정의
Data SPop(Stack* pstack) {
	int rIdx;					//인덱스 저장하기 위한 변수 선언

	if (SIsEmpty(pstack)) {				//스택이 빈 경우
		printf("Stack Memory Error!");
		exit(-1);	//return은 함수 종료, exit은 함수 관계없이 프로그램 종료
	}

	rIdx = pstack->topIndex;	//빼낼 데이터(== 마지막으로 넣은 데이터)의 스택 인덱스 저장
	pstack->topIndex--;			//전체 데이터 수 하나 감소(== 스택 데이터 삭제)

	return pstack->stackArr[rIdx];		//삭제한 스택의 데이터 반환(== 스택 빼내기)
}

//5 마지막 데이터 확인 함수 정의
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {				//스택이 빈 경우 프로그램 종료
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];	//SPop은 삭제+반환이면, SPeek는 마지막 데이터 반환만
}