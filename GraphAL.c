#include <stdio.h>
#include <stdlib.h>
#include "GraphAL.h"		//
#include "LinkedListG.h"	//

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
	pg->adjList = (List*)malloc(sizeof(List) * nv);	//���� ���� ������ ����Ʈ
	pg->numV = nv;	//������ �� ����
	pg->numE = 0;	//�ʱ� ������ ���� 0��

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));	//������ ����ŭ ������ �ټ��� ���� ����Ʈ �ʱ�ȭ
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	//����Ʈ ���� ���� ����(��� ���� ����)
	}

}

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg) {
	
	if (pg->adjList != NULL)
		free(pg->adjList);	//�������� �Ҵ�� ���� ����Ʈ ����
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