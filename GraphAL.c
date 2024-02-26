#include <stdio.h>
#include <stdlib.h>
#include "GraphAL.h"		//
#include "LinkedListG.h"	//

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
	pg->adjList = (List*)malloc(sizeof(List) * nv);	//간선 정보 저장할 리스트
	pg->numV = nv;	//정점의 수 저장
	pg->numE = 0;	//초기 간선의 수는 0개

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));	//정점의 수만큼 생성된 다수의 연결 리스트 초기화
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	//리스트 정렬 기준 설정(출력 관련 정렬)
	}

}

//그래프의 리소스 해제
void GraphDestroy(ALGraph* pg) {
	
	if (pg->adjList != NULL)
		free(pg->adjList);	//동적으로 할당된 연결 리스트 해제
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