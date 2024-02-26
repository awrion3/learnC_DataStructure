#ifndef __GRAPH_A_L_H__
#define __GRAPH_A_L_H__
//���� ����Ʈ ��� ������ �׷��� ����

#include "LinkedListG.h"	//

//���� �̸� ���ȭ
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct ual {	//������ �׷���, ���� ����Ʈ ��� ���� ����
	int numV;		//������ ��
	int numE;		//������ ��
	List* adjList;	//������ ����
} ALGraph;

//�׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);
#endif