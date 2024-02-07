#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;	//우선순위

typedef struct heapElem {	//힙의 구성 요소
	Priority pr;		//우선순위 큐 구현을 위해 사용
	HData data;
} HeapElem;

typedef struct heap {		//힙 구조 (배열 기반)
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

//함수 원형 선언
void HeapInit(Heap* ph);				   //힙 초기화 및 비었는지 확인
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);	//힙의 삽입 및 삭제
HData HDelete(Heap* ph);
#endif