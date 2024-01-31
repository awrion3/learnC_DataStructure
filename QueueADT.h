/*
배열 기반 큐(원형 큐Circular Queue)의 ADT(추상자료형)의 기능 Operations:

//1 큐의 초기화
void QueueInit(Queue* pq);

//2 큐가 비었는지 확인
int QIsEmpty(Queue* pq);

//3 큐에 데이터 저장
void Enqueue(Queue* pq, Data data);

//4 큐의 데이터 삭제 및 반환 (가장 앞선 데이터 삭제; 선입선출)
Data Dequeue(Queue* pq);

//5 큐의 데이터 확인 및 반환 (...)
Data QPeek(Queue* pq);
*/