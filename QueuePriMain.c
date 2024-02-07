#include <stdio.h>
#include "QueuePri.h"	//

int DataPriorityComp(char ch1, char ch2) {	//우선순위 비교 함수 등록
	//ch1가 우선순위 더 높을 시 (값 자체는 작을수록 높기에 ch1 < ch2이므로)
	return ch2 - ch1;	//반환값은 양수가 될 것
}

int main(void) {

	PQueue pq;			//우선순위 큐 생성
	PQueueInit(&pq, DataPriorityComp);	//우선순위 큐 초기화 및 우선순위 등록

	PEnqueue(&pq, 'A');	//문자 'A'를 최고 우선순위로 저장
	PEnqueue(&pq, 'B');	//문자 'B'를 두번째 우선순위로 저장
	PEnqueue(&pq, 'C');	//문자 'C'를 세번째 우선순위로 저장
	printf("%c \n", PDequeue(&pq));	//우선순위 큐 맨 위 하나 삭제

	PEnqueue(&pq, 'A');	//
	PEnqueue(&pq, 'B');	//
	PEnqueue(&pq, 'C');	//
	printf("%c \n", PDequeue(&pq));	//

	while (!PQIsEmpty(&pq))				//우선순위 큐가 비지 않은 동안
		printf("%c \n", PDequeue(&pq));	//노드 하나씩 삭제하며 출력

	return 0;
}