#include <stdio.h>
#include "StackL.h"	//

int main(void) {

	//스택의 생성 및 초기화
	Stack stack;

	StackInit(&stack);

	//스택에 데이터 넣기
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	//스택에서 데이터 빼기
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}