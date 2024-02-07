#include <stdio.h>
#include "QueuePri.h"	//

int DataPriorityComp(char ch1, char ch2) {	//�켱���� �� �Լ� ���
	//ch1�� �켱���� �� ���� �� (�� ��ü�� �������� ���⿡ ch1 < ch2�̹Ƿ�)
	return ch2 - ch1;	//��ȯ���� ����� �� ��
}

int main(void) {

	PQueue pq;			//�켱���� ť ����
	PQueueInit(&pq, DataPriorityComp);	//�켱���� ť �ʱ�ȭ �� �켱���� ���

	PEnqueue(&pq, 'A');	//���� 'A'�� �ְ� �켱������ ����
	PEnqueue(&pq, 'B');	//���� 'B'�� �ι�° �켱������ ����
	PEnqueue(&pq, 'C');	//���� 'C'�� ����° �켱������ ����
	printf("%c \n", PDequeue(&pq));	//�켱���� ť �� �� �ϳ� ����

	PEnqueue(&pq, 'A');	//
	PEnqueue(&pq, 'B');	//
	PEnqueue(&pq, 'C');	//
	printf("%c \n", PDequeue(&pq));	//

	while (!PQIsEmpty(&pq))				//�켱���� ť�� ���� ���� ����
		printf("%c \n", PDequeue(&pq));	//��� �ϳ��� �����ϸ� ���

	return 0;
}