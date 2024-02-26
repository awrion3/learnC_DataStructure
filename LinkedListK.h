#ifndef __LINKED_LIST_K_H__
#define __LINKED_LIST_K_H__		//더미 노드 사용 단방향 연결 리스트 재활용

#define TRUE 1				//매크로 상수 정의 전처리 지시자
#define FALSE 0

//형 정의
typedef int LData;			//int형을 LData 자료형으로 정의

//구조체 정의
typedef struct node {		//동적할당 기반 연결 리스트를 정의하기 위한 노드 구조체
	LData data;				//리스트 데이터 저장
	struct node* next;		//다음 데이터를 저장한 구조체와 연결
} Node;

typedef struct linkedList {	//연결 리스트를 정의한 구조체
	//연결 리스트의 더미 노드를 가리키는 구조체 포인터
	Node* head;
	//연결 리스트의 참조/삭제를 돕는 구조체 포인터
	Node* before;
	Node* cur;				  //모두 Main에 선언하지 않음: 다수의 리스트 자료구조에 대비)

	int numOfData;						//전체 데이터 수 기록
	int (*comp)(LData d1, LData d2);	//정렬 기준 등록
} LinkedList;

typedef LinkedList List;	//연결 리스트 관련 구조체 자료형을 List형으로 재정의

//함수 원형 선언
void ListInit(List* plist);				//리스트 초기화
void LInsert(List* plist, LData data);	//데이터 저장

int LFirst(List* plist, LData* pdata);	//첫번째 데이터 참조
int LNext(List* plist, LData* pdata);	//두번째 이후 데이터 참조

LData LRemove(List* plist);				//참조한 데이터 삭제
int LCount(List* plist);				//저장된 데이터 수 반환

//정렬 삽입 기준 등록 함수 추가//
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));
#endif
