#include <stdio.h>
#include "GraphAL.h"	//

int main(void) {

	//�׷����� ���� �� �ʱ�ȭ
	ALGraph graph;		
	GraphInit(&graph, 5);	//������ ��

	//�׷��� ���� �� ����
	AddEdge(&graph, A, B); AddEdge(&graph, A, D);
	AddEdge(&graph, B, C); AddEdge(&graph, C, D);
	AddEdge(&graph, D, E); AddEdge(&graph, E, A);

	//�׷��� ���� ���� ���
	ShowGraphEdgeInfo(&graph);
	
	//�׷��� ���ҽ� �Ҹ�
	GraphDestroy(&graph);	//�ʱ�ȭ �������� �Ҵ�� ������ �޸� �Ҹ�

	return 0;
}