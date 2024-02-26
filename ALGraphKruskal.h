#ifndef __A_L_GRAPH_KRUSKAL_H__
#define __A_L_GRAPH_KRUSKAL_H__

#include "LinkedListK.h"	
#include "PriQueueK.h"	//
#include "ALEdgeK.h"

//���� �̸� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct ual {	//������ �׷���, ���� ����Ʈ ��� ���� ����
	int numV;		//������ ��
	int numE;		//������ ��
	List* adjList;	//������ ����
	int* visitInfo;	//Ž���� ����� ������ ���� ���//
	PQueue pqueue;	///������ ����ġ ���� ����///
} ALGraph;

//�׷����� �ʱ�ȭ//
void GraphInit(ALGraph* pg, int nv);

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

//������ �߰�//
void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

//ũ�罺Į �˰��� ��� �ּҺ�� ���� Ʈ��(MST) ����//
void ConKruskalMST(ALGraph* pg);

//������ ����ġ ���� ���//
void ShowGraphEdgeWeightInfo(ALGraph* pg);
#endif