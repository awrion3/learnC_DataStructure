#include <stdio.h>
#include "Heap.h"	//

int main(void) {

	Heap heap;			//�� ����
	HeapInit(&heap);	//�� �ʱ�ȭ

	HInsert(&heap, 'A', 1);	//���� 'A'�� �ְ� �켱������ ����
	HInsert(&heap, 'B', 2);	//���� 'B'�� �ι�° �켱������ ����
	HInsert(&heap, 'C', 3);	//���� 'C'�� ����° �켱������ ����
	printf("%c \n", HDelete(&heap));	//�� �� �� �ϳ� ����
	
	HInsert(&heap, 'A', 1);	//�ѹ��� �� �ݺ�
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));	//...

	while (!HIsEmpty(&heap))				//���� ���� ���� ����
		printf("%c \n", HDelete(&heap));	//�� ��� �ϳ��� �����ϸ� ���

	return 0;
}