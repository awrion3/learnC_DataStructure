#include <stdio.h>
#include "Deque.h"	//

int main(void) {

	//���� ���� �� �ʱ�ȭ
	Deque* deq;
	DequeInit(&deq);

	//���� ������ �����ϱ�
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	//�� �Ӹ����� ������ ������
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));

	//���� ������ �����ϱ�
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	//�� �������� ������ ������
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));

	return 0;
}