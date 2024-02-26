#ifndef __A_L_EDGE_K_H__
#define __A_L_EDGE_K_H__
//가중치가 포함된 간선의 표현을 위한 구조체 정의

typedef struct edge {
	int v1;			//간선이 연결하는 첫 번째 정점
	int v2;			//간선이 연결하는 두 번째 정점
	int weight;		//간선의 가중치
} Edge;

#endif