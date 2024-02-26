#include <stdio.h>
#include "GraphAL.h"	//

int main(void) {

	//그래프의 생성 및 초기화
	ALGraph graph;		
	GraphInit(&graph, 5);	//정점의 수

	//그래프 정점 간 연결
	AddEdge(&graph, A, B); AddEdge(&graph, A, D);
	AddEdge(&graph, B, C); AddEdge(&graph, C, D);
	AddEdge(&graph, D, E); AddEdge(&graph, E, A);

	//그래프 간선 정보 출력
	ShowGraphEdgeInfo(&graph);
	
	//그래프 리소스 소멸
	GraphDestroy(&graph);	//초기화 과정에서 할당된 별도의 메모리 소멸

	return 0;
}