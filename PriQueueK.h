#ifndef __PRI_QUEUE_K_H__
#define __PRI_QUEUE_K_H__

#include "HeapK.h"	//힙 자료구조 활용하기 위해 포함

//사용자 형 정의
typedef Heap PQueue;
typedef HData PQData;

//함수 원형 선언
//우선순위 큐의 초기화
void PQueueInit(PQueue* ppq, PriorityComp pc);
//우선순위 큐의 비었는지 확인
int PQIsEmpty(PQueue* ppq);

//우선순위 큐의 데이터 저장
void PEnqueue(PQueue* ppq, PQData data);
//우선순위 큐의 데이터 삭제
PQData PDequeue(PQueue* ppq);
#endif