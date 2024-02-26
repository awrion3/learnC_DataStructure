#ifndef __A_L_GRAPH_D_F_S_H__
#define __A_L_GRAPH_D_F_S_H__
//���� ����Ʈ ��� ������ �׷��� ����

#include "LinkedListGD.h"	//

//���� �̸� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct ual {	//������ �׷���, ���� ����Ʈ ��� ���� ����
	int numV;		//������ ��
	int numE;		//������ ��
	List* adjList;	//������ ����
	int* visitInfo;	//Ž���� ����� ������ ���� ���//
} ALGraph;

//�׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

///�׷��� Ž��(DFS ���� �켱 Ž�� �˰��� ����Ͽ� ���� ���)
void DFShowGraphVertex(ALGraph* pg, int startV);
#endif