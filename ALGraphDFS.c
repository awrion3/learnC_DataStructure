#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"		//
#include "LinkedListGD.h"	//
#include "ArrayStackGD.h"	///

//
int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

//�׷����� �ʱ�ȭ
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
}

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg) {

	if (pg->adjList != NULL)
		free(pg->adjList);		//�������� �Ҵ�� ���� ����Ʈ ����

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);	//�������� �Ҵ�� �迭 �Ҹ�//
}

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV) {

	//������ �׷����� ���� �߰��̹Ƿ� �ι� ȣ��
	LInsert(&(pg->adjList[fromV]), toV);	//���� fromV�� ���� ����Ʈ�� ���� toV�� ���� �߰�	
	LInsert(&(pg->adjList[toV]), fromV);	//���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�

	pg->numE++;
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

///�׷��� Ž��(DFS ���� �켱 Ž�� �˰��� ����Ͽ� ���� ���)
//�׷��� ������ �湮�� ����
int VisitVertex(ALGraph* pg, int visitV) {	//�ι�° ���ڷ� ���޵� �̸��� ������ �湮
	if (pg->visitInfo[visitV] == 0) {	//�ش� ������ ó�� �湮�� ���	
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);		//�湮�� ������ �̸��� ���

		return TRUE;					//�湮 ����
	}
	return FALSE;						//�湮 ����
}

//�׷��� Ž�� ���� ���� ���
void DFShowGraphVertex(ALGraph* pg, int startV) {
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);			//��� Ž���� ���� ������ �ʱ�ȭ
	VisitVertex(pg, visitV);	//���� ������ �湮
	SPush(&stack, visitV);		//���� ������ ������ ���ÿ� ����

	//visitV ������ ����� ������ �ִ��� Ž���ϴ� while��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {

		//visitV�� ����� ������ ������ nextV�� ��� ���¿��� ���� �����
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) {	//���� ������ �湮 ����������,
			SPush(&stack, visitV);	//visitV�� ��� ������ ������ Push
			visitV = nextV;			//���� �������� ����
			visitFlag = TRUE;
		}
		else {									//�׷��� ������
			//visitV ������ ����� �ٸ� �������� �ִ��� Ž���ϴ� while��
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE){

				if (VisitVertex(pg, nextV) == TRUE) {	//���� ������ �湮 ����������,
					SPush(&stack, visitV);	//visitV�� ��� ������ ������ Push
					visitV = nextV;			//���� �������� ����
					visitFlag = TRUE;
					break;	//�ݺ��� Ż��
				}
			}
		}

		//�߰��� �湮�� ������ �����ٸ�
		if (visitFlag == FALSE) {
			//������ ��� Ž�� ���������� ���ƿ� ����
			if (SIsEmpty(&stack) == TRUE)	
				break;		//�ݺ��� Ż��
			else
				visitV = SPop(&stack);		//���� �ǵ��ư���
		}

		//�迭�� ����� Ž�� ���� �ʱ�ȭ
		memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	}
}