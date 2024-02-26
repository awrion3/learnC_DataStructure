#include <stdio.h>
#include <stdlib.h>
#include <string.h>			//
#include "ALGraphBFS.h"		//
#include "LinkedListGB.h"	//
#include "ArrayQueGB.h"		///

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

///�׷��� Ž��(BFS �ʺ� �켱 Ž�� �˰��� ����Ͽ� ���� ���)
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
void BFShowGraphVertex(ALGraph* pg, int startV) { //�ʺ� �켱 Ž�� �˰���
	Queue queue;	//
	int visitV = startV;
	int nextV;

	QueueInit(&queue);			//��� Ž���� ���� ť�� �ʱ�ȭ//
	VisitVertex(pg, visitV);	//���� ������ �湮

	//visitV ������ ����� ������ �ִ��� Ž���ϴ� while��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {

		if (VisitVertex(pg, nextV) == TRUE) 	//���� ������ �湮 ����������,
			Enqueue(&queue, nextV);				//nextV�� ��� �ش� ������ ������ ť�� �ֱ�//
		
		//visitV ������ ����� �ٸ� �������� �ִ��� Ž���ϴ� while��
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {

			if (VisitVertex(pg, nextV) == TRUE) 	//���� ������ �湮 ����������,
				Enqueue(&queue, nextV);				//nextV�� ��� �ش� ������ ������ ť�� �ֱ�//
		}

		//ť�� ��� Ž�� ���������� ���ƿ� ����
		if (QIsEmpty(&queue) == TRUE)
			break;						//�ݺ��� Ż��
		else
			visitV = Dequeue(&queue);	//ť���� �ϳ� ������ ���� ������ ���� while�� �ٽ� �ݺ���

		//�迭�� ����� Ž�� ���� �ʱ�ȭ
		memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	}
}