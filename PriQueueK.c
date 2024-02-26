#include "PriQueueK.h"
#include "HeapK.h"		//우선순위 큐의 기반이 되는 힙 활용

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