#ifndef __GRAPH_A_L_H__
#define __GRAPH_A_L_H__
//인접 리스트 기반 무방향 그래프 구현

#include "LinkedListG.h"	//

//정점 이름 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct ual {	//무방향 그래프, 인접 리스트 기반 구현 관련
	int numV;		//정점의 수
	int numE;		//간선의 수
	List* adjList;	//간선의 정보
} ALGraph;

//그래프의 초기화
void GraphInit(ALGraph* pg, int nv);

//그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

//간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);
#endif