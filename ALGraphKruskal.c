#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"	///
#include "LinkedListK.h"	//
#include "ArrayStackK.h"	//

//
int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

///����ġ ���� (��������) ����
int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
}

//�׷����� �ʱ�ȭ//
void GraphInit(ALGraph* pg, int nv) {

	//������ ���� �ش�Ǵ� ������ ����Ʈ �迭 ����
	pg->adjList = (List*)malloc(sizeof(List) * nv);			//���� ���� ������ ����Ʈ
	pg->numV = nv;	//������ �� ����
	pg->numE = 0;	//�ʱ� ������ ���� 0��

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);	//������ ���� ���̷� �迭 �Ҵ�//
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);		//�迭�� ��� ��Ҹ� 0���� �ʱ�ȭ//

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));	//������ ����ŭ ������ �ټ��� ���� ����Ʈ �ʱ�ȭ
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	//����Ʈ ���� ���� ����(��� ���� ����)
	}

	//�켱���� ť�� �ʱ�ȭ//
	PQueueInit(&(pg->pqueue), PQWeightComp);	//�켱���� �� ���� �Լ� ���
}

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg) {

	if (pg->adjList != NULL)
		free(pg->adjList);		//�������� �Ҵ�� ���� ����Ʈ ����

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);	//�������� �Ҵ�� �迭 �Ҹ�//
}

//������ �߰�//
void AddEdge(ALGraph* pg, int fromV, int toV, int weight) {

	//������ ����ġ ������ ������//
	Edge edge = { fromV, toV, weight };

	//������ �׷����� ���� �߰��̹Ƿ� �ι� ȣ��
	LInsert(&(pg->adjList[fromV]), toV);	//���� fromV�� ���� ����Ʈ�� ���� toV�� ���� �߰�	
	LInsert(&(pg->adjList[toV]), fromV);	//���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�

	pg->numE++;

	//������ ����ġ ������ �켱���� ť�� ����//
	PEnqueue(&(pg->pqueue), edge);
}

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg) {

	int vx;

	for (int i = 0; i < pg->numV; i++) {	//�ټ��� ���� ����Ʈ ���ʷ� ���//
		printf("%c�� ����� ����: ", i + 65);	//���� ����� ���� ����

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

///�ּ� ���� Ʈ�� ���� �׷��� Ž��//
//�׷��� ������ �湮�� ����
int VisitVertex(ALGraph* pg, int visitV) {	//�ι�° ���ڷ� ���޵� �̸��� ������ �湮
	if (pg->visitInfo[visitV] == 0) {	//�ش� ������ ó�� �湮�� ���	
		pg->visitInfo[visitV] = 1;
	//	printf("%c ", visitV + 65);		//�湮�� ������ �̸��� ���//
		return TRUE;					//�湮 ����
	}
	return FALSE;						//�湮 ����
}

//ũ�罺Į �˰��� ��� �ּҺ�� ���� Ʈ��(MST) ����//
//���� �Լ�1: ���� ������ ������ �Ҹ�
void RemoveWayEdge(ALGraph* pg, int fromV, int toV) {
	int edge;
	
	//�ش� ���� ����Ʈ ���� ����
	if (LFirst(&(pg->adjList[fromV]), &edge)) {	
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge)) {
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

//���� �Լ�2: ������ �Ҹ�
void RemoveEdge(ALGraph* pg, int fromV, int toV) {
	//������ �׷����̱⿡ �Ҹ��ų ������ 2���� ��
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	pg->numE--;
}

//���� �Լ�3: ������ ������ �ٽ� ����
void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) {
	//������ �׷����̱⿡ ������ų ������ 2���� ��
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[fromV]), fromV);
	pg->numE++;
}

//���� �Լ�4: �� ������ ����Ǿ� �ִ��� Ȯ��; DFSShowGraphVertex �Լ�(DFS �˰���) ���//
int IsConnVertex(ALGraph* pg, int v1, int v2) {	//�� ������ ����Ǿ� ������ TRUE �ƴϸ� FALSE ��ȯ
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);			//��� Ž���� ���� ������ �ʱ�ȭ
	VisitVertex(pg, visitV);	//���� ������ �湮
	SPush(&stack, visitV);		//���� ������ ������ ���ÿ� ����

	//visitV ������ ����� ������ �ִ��� Ž���ϴ� while��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		//visitV�� ����� ������ ������ nextV�� ��� ���¿��� ���� �����
		int visitFlag = FALSE;

		//������ ���ƴٴϴ� ���߿� ��ǥ�� ã�� ��� TRUE ��ȯ//
		if (nextV == v2) {
			//�Լ� ��ȯ�ϱ� �� �ʱ�ȭ ����
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE) {	//���� ������ �湮 ����������,
			SPush(&stack, visitV);		//visitV�� ��� ������ ������ Push
			visitV = nextV;				//���� �������� ����
			visitFlag = TRUE;
		}
		else {									//�׷��� ������,
			//visitV ������ ����� �ٸ� �������� �ִ��� Ž���ϴ� while��
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {

				//������ ���ƴٴϴ� ���߿� ��ǥ�� ã�� ��� TRUE ��ȯ//
				if (nextV == v2) {
					//�Լ� ��ȯ�ϱ� �� �ʱ�ȭ ����
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE) {	//���� ������ �湮 ����������,
					SPush(&stack, visitV);		//visitV�� ��� ������ ������ Push
					visitV = nextV;				//���� �������� ����
					visitFlag = TRUE;
					break;	//�ݺ� ����
				}
			}
		}

		//�߰��� �湮�� ������ �����ٸ�,
		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)	//������ ��� Ž�� ���������� ���ƿ� ������
				break;						//�ݺ��� Ż��
			else
				visitV = SPop(&stack);		//���� �ǵ��ư���
		}
	}

	//�迭�� ����� Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;	//��ǥ�� ã�� ���� ���
}

void ConKruskalMST(ALGraph* pg) {
	Edge recvEdge[20];	//������ ������ ���� ����
	Edge edge;
	int eidx = 0;

	//MST�� ������ ������ �Ʒ��� while���� �ݺ���
	while (pg->numE + 1 > pg->numV) {	//������ �� + 1 == ������ ����

		//�켱���� ť���� ����ġ�� ���� ���� ������ ���� ������
		edge = PDequeue(&(pg->pqueue));
		//�켱���� ť���� ���� ������ ������ �׷������� �����ϱ�
		RemoveEdge(pg, edge.v1, edge.v2);

		//������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ��
		if (!IsConnVertex(pg, edge.v1, edge.v2)) {
			//�����ϴ� ��ΰ� �������� �ʴ� ��쿡�� ������ ������ �ٽ� ����
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			//������ ������ ������ ������ �����ϱ�
			recvEdge[eidx++] = edge;
		}
	}

	//��� �ݺ����� ���� ��, �����Ǿ��� ������ ������ �������� �ٽ� �켱���� ť�� �����ϱ� ����
	for (int i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);	//�켱���� ť���� MST�� �̷�� ������ ������ ���� ��
}

//�켱���� ť�� ���� MST�� �̷�� ������ ����ġ ���� ���//
void ShowGraphEdgeWeightInfo(ALGraph* pg) {
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ)) {	//�켱���� ť�� ����� ��� ���� ���
		edge = PDequeue(&copyPQ);
		printf("(%c - %c), w: %d\n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}