#include <stdio.h>
#include "ALGraphDFS.h"	//

int main(void) {

	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B); AddEdge(&graph, A, D);
	AddEdge(&graph, B, C); AddEdge(&graph, D, C);
	AddEdge(&graph, D, E); AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	DFShowGraphVertex(&graph, A); printf("\n");	//A를 시작 정점으로 하여 그래프 깊이 우선 탐색 출력

	GraphDestroy(&graph);

	return 0;
}