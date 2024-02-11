#include <stdio.h>
#include "SortHeapPri.h"	//

int PriComp(int n1, int n2) {
	return n2 - n1;			//�������� ����
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	HeapInit(&heap, pc);	//�� �ʱ�ȭ

	for (int i = 0; i < n; i++)	//�����͸� ���ؿ� ���� ��� ���� �ֱ�
		HInsert(&heap, arr[i]);

	for (int i = 0; i < n; i++)	//������� �����͸� ������
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