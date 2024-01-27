#include <stdio.h>
#include "StackL.h"	//

int main(void) {

	//������ ���� �� �ʱ�ȭ
	Stack stack;

	StackInit(&stack);

	//���ÿ� ������ �ֱ�
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	//���ÿ��� ������ ����
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}