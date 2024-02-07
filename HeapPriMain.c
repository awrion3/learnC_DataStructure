#include <stdio.h>
#include "HeapPri.h"	//

int DataPriorityComp(char ch1, char ch2) {	//우선순위 비교 함수 등록
	//ch1가 우선순위 더 높을 시 (값 자체는 작을수록 높기에 ch1 < ch2이므로)
	return ch2 - ch1;	//반환값은 양수가 될 것
}

int main(void) {

	Heap heap;			//힙 생성
	HeapInit(&heap, DataPriorityComp);	//힙 초기화 및 우선순위 등록

	HInsert(&heap, 'A');	//문자 'A'를 최고 우선순위로 저장
	HInsert(&heap, 'B');	//문자 'B'를 두번째 우선순위로 저장
	HInsert(&heap, 'C');	//문자 'C'를 세번째 우선순위로 저장
	printf("%c \n", HDelete(&heap));	//힙 맨 위 하나 삭제

	HInsert(&heap, 'A');	//한번씩 더 반복
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));	//...

	while (!HIsEmpty(&heap))				//힙이 비지 않은 동안
		printf("%c \n", HDelete(&heap));	//힙 노드 하나씩 삭제하며 출력

	return 0;
}