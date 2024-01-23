#ifndef __LINKED_LIST_C_H__
#define __LINKED_LIST_C_H__
//원형 연결 리스트: 단순 연결 리스트와 달리 머리와 꼬리를 가리키는 포인터 변수 각각 두지 않아도 된다
//하나의 포인터 변수만 있어도 머리 또는 꼬리에 노드를 추가할 수 있다
#define TRUE 1
#define FALSE 0

//노드 관련 구조체 정의
typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
} Node;

//변형된 원형 연결 리스트: 하나의 포인터 변수가 머리가 아닌 꼬리를 가리키게 한다
//tail == 꼬리를 가리키는 포인터 변수, tail->next == 머리를 가리키는 포인터 변수
typedef struct CLL {
	Node* tail;

	Node* cur;
	Node* before;

	int numOfData;
} CList;

typedef CList List;

//함수 원형 선언
void ListInit(List* plist);

void LInsert(List* plsit, Data data);		//꼬리에 노드 추가
void LInsertFront(List* plist, Data data);	//머리에 노드 추가

int LFirst(List* plsit, Data* pdata);
int LNext(List* plist, Data* pdata);	//리스트 끝에 도달할 경우, 첫 노드부터 다시 조회가 시작되게 변형

Data LRemove(List* plist);
int LCount(List* plist);

#endif