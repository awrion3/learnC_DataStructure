#include <stdio.h>
#include "StackA.h"	//

int main(void) {

	//������ ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	//������ �ֱ�
	SPush(&stack, 1); SPush(&stack, 2); 
	SPush(&stack, 3); SPush(&stack, 4); 
	SPush(&stack, 5);

	//������ ����
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));	//���� ���: 5 4 3 2 1

	return 0;
}