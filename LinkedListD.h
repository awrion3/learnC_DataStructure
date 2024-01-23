#ifndef __LINKED_LIST_D_H__
#define __LINKED_LIST_D_H__
//(더미 노드 사용 안하는 경우의, 새 노드를 머리에 추가하는) 양방향 연결 리스트 
#define TRUE 1
#define FALSE 0

//노드 관련
typedef int Data;

typedef struct node {
	Data data;
	struct node* next;	//오른쪽 노드 가리키는 포인터 변수
	struct node* prev;	//왼쪽 노드 가리키는 포인터 변수
} Node;

//양방향 연결 리스트 관련
typedef struct LinkedListD {
	Node* head;			
	Node* cur;			//양방향이기에 before 포인터 변수를 사용해 유지할 필요 없음
	int numOfData;
} DLinkedList;

typedef DLinkedList List;

//양방향 연결 리스트 관련 함수
void ListInit(List* plist);				 //초기화
void LInsert(List* plist, Data data);	 //저장

int LFirst(List* plist, Data* pdata);	 //조회
int LNext(List* plist, Data* pdata);	 //오른쪽 조회
int LPrevious(List* plist, Data* pdata); //왼족 조회//

int LCount(List* plist);				 //수
#endif