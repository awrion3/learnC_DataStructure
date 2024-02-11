#ifndef __SORT_HEAP_PRI_H__
#define __SORT_HEAP_PRI_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef int HData;	//힙 정렬과 관련하여 변경//
typedef int (*PriorityComp)(HData d1, HData d2);
//우선순위를 미리 설정하지 않아도 되게끔 재구성
//예시: d1가 d2보다 우선순위가 높으면 + 값 반환, 반대는 - 값 반환, 동일시 0 값 정수 반환

typedef struct heap {		//힙 구조 (배열 기반)
	PriorityComp* comp;			//우선순위 비교 함수 등록 관련 함수 포인터// 
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

//함수 원형 선언
void HeapInit(Heap* ph, PriorityComp pc);	//힙 초기화(우선순위 비교 함수 등록) 및 비었는지 확인
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);			//힙의 삽입(우선순위 계산 관련 인자는 필요 없어짐) 및 삭제
HData HDelete(Heap* ph);
#endif