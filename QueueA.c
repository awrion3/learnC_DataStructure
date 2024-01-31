#include <stdio.h>
#include <stdlib.h>
#include "QueueA.h"	//

//큐 초기화 함수
void QueueInit(Queue* pq) {
	pq->front = 0;	//따라서 텅빈 경우
	pq->rear = 0;	//둘다 동일 인덱스 저장(동일 위치에 있다는 뜻)
}

//큐 비었는지 확인 함수
int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)	//큐가 빈 경우 참 반환
		return TRUE;
	else						//아닌 경우 거짓 반환
		return FALSE;
}

//큐의 다음 위치에 해당하는 인덱스 값 반환하는 함수//
int NextPosIdx(int pos) {		
	if (pos == QUE_LEN - 1)		//배열 마지막 요소의 인덱스 값이라면
		return 0;					//앞으로 다시 이동해야 함(회전)
	else						//아닌 경우
		return pos + 1;				//다음 위치로 이동
}

//큐에 데이터 추가
void Enqueue(Queue* pq, Data data) {
	//큐가 꽉찬 경우 프로그램 종료
	if (NextPosIdx(pq->rear) == pq->front) {	
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);	//R을 한 칸 다음으로 이동
	pq->queArr[pq->rear] = data;		//해당 위치에 데이터 저장
}

//큐의 데이터 삭제
Data Dequeue(Queue* pq) {
	//큐가 빈 경우 프로그램 종료
	if (QIsEmpty(pq)) {							
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);	//F를 한 칸 다음으로 이동
	return pq->queArr[pq->front];		//삭제될 데이터 반환(엄밀히 보면 다음 차례에 삭제됨)
}

//큐의 데이터 조회
Data QPeek(Queue* pq) {
	//큐가 빈 경우 프로그램 종료
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];	//다음 인덱스의 해당 데이터 반환(인덱스 이동은 안함)
}