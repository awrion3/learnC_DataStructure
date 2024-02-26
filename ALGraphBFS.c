#include <stdio.h>
#include <stdlib.h>
#include <string.h>			//
#include "ALGraphBFS.h"		//
#include "LinkedListGB.h"	//
#include "ArrayQueGB.h"		///

//
int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

//그래프의 초기화
void GraphInit(ALGraph* pg, int nv) {

	//정점의 수에 해당되는 길이의 리스트 배열 생성
	pg->adjList = (List*)malloc(sizeof(List) * nv);			//간선 정보 저장할 리스트
	pg->numV = nv;	//정점의 수 저장
	pg->numE = 0;	//초기 간선의 수는 0개

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);	//정점의 수를 길이로 배열 할당//
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);		//배열의 모든 요소를 0으로 초기화//

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));	//정점의 수만큼 생성된 다수의 연결 리스트 초기화
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	//리스트 정렬 기준 설정(출력 관련 정렬)
	}
}

//그래프의 리소스 해제
void GraphDestroy(ALGraph* pg) {

	if (pg->adjList != NULL)
		free(pg->adjList);		//동적으로 할당된 연결 리스트 해제

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);	//동적으로 할당된 배열 소멸//
}

//간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV) {

	//무방향 그래프의 간선 추가이므로 두번 호출
	LInsert(&(pg->adjList[fromV]), toV);	//정점 fromV의 연결 리스트에 정점 toV의 정보 추가	
	LInsert(&(pg->adjList[toV]), fromV);	//정점 toV의 연결 리스트에 정점 fromV의 정보 추가

	pg->numE++;
}

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg) {

	int vx;

	for (int i = 0; i < pg->numV; i++) {	//다수의 연결 리스트 차례로 출력//
		printf("%c와 연결된 정점: ", i + 65);	//문자 출력을 위해 더함

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

///그래프 탐색(BFS 너비 우선 탐색 알고리즘 기반하여 정점 출력)
//그래프 정점의 방문을 진행
int VisitVertex(ALGraph* pg, int visitV) {	//두번째 인자로 전달된 이름의 정점에 방문
	if (pg->visitInfo[visitV] == 0) {	//해당 정점에 처음 방문한 경우	
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);		//방문한 정점의 이름을 출력

		return TRUE;					//방문 성공
	}
	return FALSE;						//방문 실패
}

//그래프 탐색 정점 정보 출력
void BFShowGraphVertex(ALGraph* pg, int startV) { //너비 우선 탐색 알고리즘
	Queue queue;	//
	int visitV = startV;
	int nextV;

	QueueInit(&queue);			//경로 탐색을 위한 큐의 초기화//
	VisitVertex(pg, visitV);	//시작 정점을 방문

	//visitV 정점에 연결된 정점이 있는지 탐색하는 while문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {

		if (VisitVertex(pg, nextV) == TRUE) 	//다음 정점에 방문 성공했으면,
			Enqueue(&queue, nextV);				//nextV에 담긴 해당 정점의 정보를 큐에 넣기//
		
		//visitV 정점에 연결된 다른 정점들이 있는지 탐색하는 while문
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {

			if (VisitVertex(pg, nextV) == TRUE) 	//다음 정점에 방문 성공했으면,
				Enqueue(&queue, nextV);				//nextV에 담긴 해당 정점의 정보를 큐에 넣기//
		}

		//큐가 비면 탐색 시작점으로 돌아온 것임
		if (QIsEmpty(&queue) == TRUE)
			break;						//반복문 탈출
		else
			visitV = Dequeue(&queue);	//큐에서 하나 꺼내며 다음 정점에 대해 while문 다시 반복됨

		//배열에 저장된 탐색 정보 초기화
		memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	}
}