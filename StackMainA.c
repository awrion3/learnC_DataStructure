#include <stdio.h>
#include "StackA.h"	//

int main(void) {

	//스택의 생성 및 초기화
	Stack stack;
	StackInit(&stack);

	//데이터 넣기
	SPush(&stack, 1); SPush(&stack, 2); 
	SPush(&stack, 3); SPush(&stack, 4); 
	SPush(&stack, 5);

	//데이터 빼기
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));	//실행 결과: 5 4 3 2 1

	return 0;
}