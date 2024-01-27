#include <stdlib.h>
#include <ctype.h>	//int isdigit(int ch); ch로 전달된 문자의 내용이 10진수라면 1 반환
#include <string.h>	//void* memset(void* ptr, int val, size_t len); 
					//ptr로 전달된 주소의 메모리서부터 len 바이트를 val의 값으로 채운다
#include "LStack.h"	//

//연산자의 우선순위 정보를 반환하는 함수 정의
int GetOpPrec(char op) {	
	switch (op) 
	{
		case '*' : 
		case '/' :
			return 3;	//가장 높은 연산 우선순위
		case '+' :
		case '-' :
			return 2;	//중간 연산 우선순위
		case '(' :
			return 1;	//가장 낮은 연산 운선순위
		//')'는 다른 연산자와 우선순위 비교할 필요 없으므로 제외
	}
	return -1;		//등록되지 않은 연산자
}

//GetOpPrec의 결과를 바탕으로 두 연산자의 우선순위를 비교하여, 그 결과를 반환하는 함수 정의
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);	//각 연산자의 우선순위 저장
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)			//op1의 우선순위가 더 높은 경우
		return 1;
	else if (op1Prec < op2Prec)		//op2의 우선순위가 더 높은 경우
		return -1;
	else							//같은 경우
		return 0;
}

//후위표기법으로 변환하는 함수 정의
void ConvToPost(char exp[]) {
	
	Stack stack;	//스택 구조체 선언//
	
	int expLen = strlen(exp);			//중위표기법으로 표기된 문자열 길이 구하기
	char* convExp = (char*)malloc(expLen + 1);	//널 문자 고려하여 문자열 동적할당

	int i, idx = 0;		//관련 변수 선언
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);	//할당된 배열 크기만큼을 0으로 초기화 (string.h)

	StackInit(&stack);	//스택 초기화//

	for (i = 0; i < expLen; i++) {
		tok = exp[i];	//exp로 전달된 수식 문자열을 한 문자씩 tok에 임시 저장

		if (isdigit(tok)) {			//tok에 저장된 문자가 숫자인지 확인 (ctype.h)
			convExp[idx++] = tok;	//1. 숫자에 해당하면 배열 convExp에 바로 저장
		}
		else {						//2. 숫자가 아닌 연산자라면, 스택을 이용
			switch (tok) {
				case '(' :				//여는 소괄호면 해당 소괄호를 스택에 쌓기
					SPush(&stack, tok);
					break;
				case ')' :				//닫는 소괄호면 스택에 있는 연산자들 빼내기
					while (1) {
						popOp = SPop(&stack);

						if (popOp == '(')	//또 다른 여는 소괄호를 만나면 반복 종료
							break;

						convExp[idx++] = popOp;	//연산자 배열 convExp에 저장
					}
					break;
				case '+': case '-': 
				case '*': case '/':	//사칙연산인 경우 우선순위 고려해 스택에 쌓거나 빼기
					//스택이 비지 않았고, 스택 맨 위의 연산자op1와 현 연산자op2 중 op1이 우선순위 높은 동안,
					while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
						convExp[idx++] = SPop(&stack);		//스택에서 연산자 빼서 배열 convExp에 저장
					
					//현 연산자인 op2가 우선순위 더 높게 되면, 스택에 쌓기
					SPush(&stack, tok);
					break;
			}
		}
	}

	while (!SIsEmpty(&stack))			//스택에 남아있는 모든 연산자를
		convExp[idx++] = SPop(&stack);	//배열 convExp로 이동

	strcpy(exp, convExp);		//후위표기법으로 변환된 수식 문자열을 기존 배열로 복사하고
	free(convExp);				//문자열 변환을 위해 동적할당한 공간은 해제
}