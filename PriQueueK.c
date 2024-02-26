#include "PriQueueK.h"
#include "HeapK.h"		//�켱���� ť�� ����� �Ǵ� �� Ȱ��

void PQueueInit(PQueue* ppq, PriorityComp pc) {
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue* ppq) {
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data) {
	HInsert(ppq, data);
}

PQData PDequeue(PQueue* ppq) {
	return HDelete(ppq);
}