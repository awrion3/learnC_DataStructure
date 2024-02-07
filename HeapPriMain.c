#include <stdio.h>
#include "HeapPri.h"	//

int DataPriorityComp(char ch1, char ch2) {	//�켱���� �� �Լ� ���
	//ch1�� �켱���� �� ���� �� (�� ��ü�� �������� ���⿡ ch1 < ch2�̹Ƿ�)
	return ch2 - ch1;	//��ȯ���� ����� �� ��
}

int main(void) {

	Heap heap;			//�� ����
	HeapInit(&heap, DataPriorityComp);	//�� �ʱ�ȭ �� �켱���� ���

	HInsert(&heap, 'A');	//���� 'A'�� �ְ� �켱������ ����
	HInsert(&heap, 'B');	//���� 'B'�� �ι�° �켱������ ����
	HInsert(&heap, 'C');	//���� 'C'�� ����° �켱������ ����
	printf("%c \n", HDelete(&heap));	//�� �� �� �ϳ� ����

	HInsert(&heap, 'A');	//�ѹ��� �� �ݺ�
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));	//...

	while (!HIsEmpty(&heap))				//���� ���� ���� ����
		printf("%c \n", HDelete(&heap));	//�� ��� �ϳ��� �����ϸ� ���

	return 0;
}