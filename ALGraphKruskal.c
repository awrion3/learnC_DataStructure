#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"	///
#include "LinkedListK.h"	//
#include "ArrayStackK.h"	//

//
int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

///가중치 기준 (내림차순) 정렬
int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
}

//그래프의 초기화//
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

	//우선순위 큐의 초기화//
	PQueueInit(&(pg->pqueue), PQWeightComp);	//우선순위 비교 기준 함수 등록
}

//그래프의 리소스 해제
void GraphDestroy(ALGraph* pg) {

	if (pg->adjList != NULL)
		free(pg->adjList);		//동적으로 할당된 연결 리스트 해제

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);	//동적으로 할당된 배열 소멸//
}

//간선의 추가//
void AddEdge(ALGraph* pg, int fromV, int toV, int weight) {

	//간선의 가중치 정보를 포함함//
	Edge edge = { fromV, toV, weight };

	//무방향 그래프의 간선 추가이므로 두번 호출
	LInsert(&(pg->adjList[fromV]), toV);	//정점 fromV의 연결 리스트에 정점 toV의 정보 추가	
	LInsert(&(pg->adjList[toV]), fromV);	//정점 toV의 연결 리스트에 정점 fromV의 정보 추가

	pg->numE++;

	//간선의 가중치 정보를 우선순위 큐에 저장//
	PEnqueue(&(pg->pqueue), edge);
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

///최소 신장 트리 관련 그래프 탐색//
//그래프 정점의 방문을 진행
int VisitVertex(ALGraph* pg, int visitV) {	//두번째 인자로 전달된 이름의 정점에 방문
	if (pg->visitInfo[visitV] == 0) {	//해당 정점에 처음 방문한 경우	
		pg->visitInfo[visitV] = 1;
	//	printf("%c ", visitV + 65);		//방문한 정점의 이름을 출력//
		return TRUE;					//방문 성공
	}
	return FALSE;						//방문 실패
}

//크루스칼 알고리즘 기반 최소비용 신장 트리(MST) 구성//
//구성 함수1: 한쪽 방향의 간선의 소멸
void RemoveWayEdge(ALGraph* pg, int fromV, int toV) {
	int edge;
	
	//해당 연결 리스트 관련 삭제
	if (LFirst(&(pg->adjList[fromV]), &edge)) {	
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge)) {
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

//구성 함수2: 간선의 소멸
void RemoveEdge(ALGraph* pg, int fromV, int toV) {
	//무방향 그래프이기에 소멸시킬 간선은 2개가 됨
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	pg->numE--;
}

//구성 함수3: 삭제된 간선을 다시 삽입
void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) {
	//무방향 그래프이기에 복구시킬 간선은 2개가 됨
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[fromV]), fromV);
	pg->numE++;
}

//구성 함수4: 두 정점이 연결되어 있는지 확인; DFSShowGraphVertex 함수(DFS 알고리즘) 대신//
int IsConnVertex(ALGraph* pg, int v1, int v2) {	//두 정점이 연결되어 있으면 TRUE 아니면 FALSE 반환
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);			//경로 탐색을 위한 스택의 초기화
	VisitVertex(pg, visitV);	//시작 정점을 방문
	SPush(&stack, visitV);		//시작 정점의 정보를 스택에 저장

	//visitV 정점에 연결된 정점이 있는지 탐색하는 while문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		//visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하 진행됨
		int visitFlag = FALSE;

		//정점을 돌아다니는 도중에 목표를 찾는 경우 TRUE 반환//
		if (nextV == v2) {
			//함수 반환하기 전 초기화 진행
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE) {	//다음 정점에 방문 성공했으면,
			SPush(&stack, visitV);		//visitV에 담긴 정점의 정보를 Push
			visitV = nextV;				//다음 정점으로 갱신
			visitFlag = TRUE;
		}
		else {									//그렇지 않으면,
			//visitV 정점에 연결된 다른 정점들이 있는지 탐색하는 while문
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {

				//정점을 돌아다니는 도중에 목표를 찾는 경우 TRUE 반환//
				if (nextV == v2) {
					//함수 반환하기 전 초기화 진행
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE) {	//다음 정점에 방문 성공했으면,
					SPush(&stack, visitV);		//visitV에 담긴 정점의 정보를 Push
					visitV = nextV;				//다음 정점으로 갱신
					visitFlag = TRUE;
					break;	//반복 중지
				}
			}
		}

		//추가로 방문한 정점이 없었다면,
		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)	//스택이 비면 탐색 시작점으로 돌아온 것으로
				break;						//반복문 탈출
			else
				visitV = SPop(&stack);		//길을 되돌아간다
		}
	}

	//배열에 저장된 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;	//목표를 찾지 못한 경우
}

void ConKruskalMST(ALGraph* pg) {
	Edge recvEdge[20];	//복원할 간선의 정보 저장
	Edge edge;
	int eidx = 0;

	//MST를 형성할 때까지 아래의 while문을 반복함
	while (pg->numE + 1 > pg->numV) {	//간선의 수 + 1 == 정점의 수임

		//우선순위 큐에서 가중치가 제일 높은 간선의 정보 꺼내기
		edge = PDequeue(&(pg->pqueue));
		//우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제하기
		RemoveEdge(pg, edge.v1, edge.v2);

		//간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인
		if (!IsConnVertex(pg, edge.v1, edge.v2)) {
			//연결하는 경로가 존재하지 않는 경우에는 삭제한 간선을 다시 복원
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			//복원한 간선의 정보를 별도로 저장하기
			recvEdge[eidx++] = edge;
		}
	}

	//모든 반복문이 끝난 뒤, 삭제되었다 복원한 간선의 정보들을 다시 우선순위 큐에 저장하기 위함
	for (int i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);	//우선순위 큐에는 MST를 이루는 간선의 정보만 남게 됨
}

//우선순위 큐에 남은 MST를 이루는 간선의 가중치 정보 출력//
void ShowGraphEdgeWeightInfo(ALGraph* pg) {
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ)) {	//우선순위 큐에 저장된 모든 정보 출력
		edge = PDequeue(&copyPQ);
		printf("(%c - %c), w: %d\n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}