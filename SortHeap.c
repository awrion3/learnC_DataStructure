#include <stdio.h>
#include "SortHeapPri.h"	//

int PriComp(int n1, int n2) {
	return n2 - n1;			//오름차순 정렬
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	HeapInit(&heap, pc);	//힙 초기화

	for (int i = 0; i < n; i++)	//데이터를 기준에 따라서 모두 힙에 넣기
		HInsert(&heap, arr[i]);

	for (int i = 0; i < n; i++)	//순서대로 데이터를 꺼내기
		arr[i] = HDelete(&heap);
}

int main(void) {

	int arr[4] = { 3, 2, 4, 1 };

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}