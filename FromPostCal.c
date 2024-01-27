#include <string.h>
#include <ctype.h>
#include "LStack.h"	//

int PostCal(char exp[]) {
	
	Stack stack;
	int expLen = strlen(exp);	//수식 문자열 길이 구하기
	char tok, op1, op2;

	StackInit(&stack);	//스택 초기화

	for (int i = 0; i < expLen; i++) {	//수식을 구성하는 문자 각각을 대상으로 반복
		tok = exp[i];	//한 문자씩 tok에 저장

		if (isdigit(tok)) {				//문자가 정수라면
			SPush(&stack, tok - '0');	//숫자로 변환하여 스택에 넣기
		}
		else {							//문자가 연산자라면
			op2 = SPop(&stack);			//스택에서 숫자를 꺼내는데, 두번째 피연산자로 저장
			op1 = SPop(&stack);			//..., 첫번째 피연산자로 저장

			switch (tok) {				//해당 연산자가 무엇인지 파악해 두 피연산자를 연산하기
			case '+':
				SPush(&stack, op1 + op2);	//연산한 결과 스택에 다시 넣기
				break;
			case '-':
				SPush(&stack, op1 - op2);	//...
				break;
			case '*':
				SPush(&stack, op1 * op2);	//...
				break;
			case '/':
				SPush(&stack, op1 / op2);	//...
				break;
			}
		}
	}
	return SPop(&stack);	//최종 연산 결과를 스택에서 꺼내어 반환
}