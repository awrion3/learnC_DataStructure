/*
그래프(Graph)의 추상자료형(ADT) 기능 명세:
(인접 리스트(Adjacent List) 기반 그래프 = 연결 리스트 활용)

//1 그래프 초기화
void GraphInit(ALGraph *pg, int nv);

//2 그래프 초기화에서 할당한 리소스 반환
void GraphDestory(ALGraph *pg); 

//3 그래프에 간선 추가
void AddEdge(ALGraph *pg, int fromV, int toV);

//4 그래프의 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg);
*/