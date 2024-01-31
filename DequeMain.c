#include <stdio.h>
#include "Deque.h"	//

int main(void) {

	//덱의 생성 및 초기화
	Deque* deq;
	DequeInit(&deq);

	//덱에 데이터 저장하기
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	//덱 머리에서 데이터 꺼내기
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));

	//덱에 데이터 저장하기
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	//덱 꼬리에서 데이터 꺼내기
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));

	return 0;
}