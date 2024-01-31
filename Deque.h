#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;		 //데이터 타입

typedef struct node {	 //연결 리스트(양방향) 기반
	Data data;
	struct node* next;
	struct node* prev;
} Node;

typedef struct dlDeque { //양방향 리스트 기반 덱 구현
	Node* head;
	Node* tail;
} DLDeque;

typedef DLDeque Deque;

//함수 원형 선언
void DequeInit(Deque* pdeq);	//초기화 및 상태 확인
int DQIsEmpty(Deque* pdeq);

void DQAddFirst(Deque* pdeq, Data data);	//데이터 넣기
void DQAddLast(Deque* pdeq, Data data);

Data DQRemoveFirst(Deque* pdeq);			//데이터 빼기
Data DQRemoveLast(Deque* pdeq);

Data DQGetFirst(Deque* pdeq);	//데이터 참조
Data DQGetLast(Deque* pdeq);
#endif