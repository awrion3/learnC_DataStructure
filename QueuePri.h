#ifndef __QUEUE_PRI_H__
#define __QUEUE_PRI_H__

#include "HeapPri.h"	//�� �ڷᱸ�� Ȱ���ϱ� ���� ����

//����� �� ����
typedef Heap PQueue;
typedef HData PQData;

//�Լ� ���� ����
//�켱���� ť�� �ʱ�ȭ
void PQueueInit(PQueue* ppq, PriorityComp pc);
//�켱���� ť�� ������� Ȯ��
int PQIsEmpty(PQueue* ppq);

//�켱���� ť�� ������ ����
void PEnqueue(PQueue* ppq, PQData data);
//�켱���� ť�� ������ ����
PQData PDequeue(PQueue* ppq);
#endif