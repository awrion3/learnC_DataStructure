#include <stdio.h>
#include "Heap.h"	//

int main(void) {

	Heap heap;			//힙 생성
	HeapInit(&heap);	//힙 초기화

	HInsert(&heap, 'A', 1);	//문자 'A'를 최고 우선순위로 저장
	HInsert(&heap, 'B', 2);	//문자 'B'를 두번째 우선순위로 저장
	HInsert(&heap, 'C', 3);	//문자 'C'를 세번째 우선순위로 저장
	printf("%c \n", HDelete(&heap));	//힙 맨 위 하나 삭제
	
	HInsert(&heap, 'A', 1);	//한번씩 더 반복
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));	//...

	while (!HIsEmpty(&heap))				//힙이 비지 않은 동안
		printf("%c \n", HDelete(&heap));	//힙 노드 하나씩 삭제하며 출력

	return 0;
}