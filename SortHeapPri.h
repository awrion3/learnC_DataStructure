#ifndef __SORT_HEAP_PRI_H__
#define __SORT_HEAP_PRI_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef int HData;	//�� ���İ� �����Ͽ� ����//
typedef int (*PriorityComp)(HData d1, HData d2);
//�켱������ �̸� �������� �ʾƵ� �ǰԲ� �籸��
//����: d1�� d2���� �켱������ ������ + �� ��ȯ, �ݴ�� - �� ��ȯ, ���Ͻ� 0 �� ���� ��ȯ

typedef struct heap {		//�� ���� (�迭 ���)
	PriorityComp* comp;			//�켱���� �� �Լ� ��� ���� �Լ� ������// 
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

//�Լ� ���� ����
void HeapInit(Heap* ph, PriorityComp pc);	//�� �ʱ�ȭ(�켱���� �� �Լ� ���) �� ������� Ȯ��
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);			//���� ����(�켱���� ��� ���� ���ڴ� �ʿ� ������) �� ����
HData HDelete(Heap* ph);
#endif