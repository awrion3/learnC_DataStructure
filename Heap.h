#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;	//�켱����

typedef struct heapElem {	//���� ���� ���
	Priority pr;		//�켱���� ť ������ ���� ���
	HData data;
} HeapElem;

typedef struct heap {		//�� ���� (�迭 ���)
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

//�Լ� ���� ����
void HeapInit(Heap* ph);				   //�� �ʱ�ȭ �� ������� Ȯ��
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);	//���� ���� �� ����
HData HDelete(Heap* ph);
#endif