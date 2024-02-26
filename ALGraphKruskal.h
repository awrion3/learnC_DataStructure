#ifndef __A_L_GRAPH_KRUSKAL_H__
#define __A_L_GRAPH_KRUSKAL_H__

#include "LinkedListK.h"	
#include "PriQueueK.h"	//
#include "ALEdgeK.h"

//정점 이름 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct ual {	//무방향 그래프, 인접 리스트 기반 구현 관련
	int numV;		//정점의 수
	int numE;		//간선의 수
	List* adjList;	//간선의 정보
	int* visitInfo;	//탐색이 진행된 정점의 정보 담기//
	PQueue pqueue;	///간선의 가중치 정보 저장///
} ALGraph;

//그래프의 초기화//
void GraphInit(ALGraph* pg, int nv);

//그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

//간선의 추가//
void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

//크루스칼 알고리즘 기반 최소비용 신장 트리(MST) 구성//
void ConKruskalMST(ALGraph* pg);

//간선의 가중치 정보 출력//
void ShowGraphEdgeWeightInfo(ALGraph* pg);
#endif