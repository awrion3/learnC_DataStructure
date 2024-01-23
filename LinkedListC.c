#include <stdio.h>
#include <stdlib.h>
#include "LinkedListC.h"

//리스트 초기화 함수 정의
void ListInit(List* plist) {
	plist->tail = NULL;	//변형된 원형 연결 리스트(하나의 포인터를, 머리가 아닌 꼬리를 가리키게 함)

	plist->cur = NULL;
	plist->before = NULL;
	
	plist->numOfData = 0;
}

//데이터 추가 함수 정의
void LInsertFront(List* plist, Data data) {	  //머리에 노드 추가하는 함수//
	//새 노드 생성 후 데이터 저장
	Node* newNode = (Node*)malloc(sizeof(Node));	
	newNode->data = data;

	if (plist->tail == NULL) {		//tail이 아무것도 가리키지 않는다면
		plist->tail = newNode;		//새 노드를 가리키게 함
		newNode->next = newNode;	//새 노드는 자기자신을 가리켜야 함(원형 연결 리스트이므로)
	}
	else {							//두번째 이후의 노드라면,
		newNode->next = plist->tail->next;	//원래의 tail의 next(머리) 노드를 새 노드의 다음으로 연결
		plist->tail->next = newNode;		//새 노드를 tail의 next(머리) 노드로 지정
	}
	plist->numOfData++;		//전체 데이터 수 하나 증가
}

void LInsert(List* plist, Data data) {		//꼬리에 노드 추가하는 함수//
	//새 노드 생성 후 데이터 저장
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {		//tail이 아무것도 가리키지 않는다면..
		plist->tail = newNode;		//...위와 동일
		newNode->next = newNode;	//(첫 노드는 그 자체로 머리이자 꼬리이기 때문)
	}
	else {							//두번째 이후의 노드라면,
		newNode->next = plist->tail->next;	//tail이 가리키는 노드가 추가된 새 노드인 것이 위와의 차이일 뿐,
		plist->tail->next = newNode;		//...따라서 여기까지는 위와 동일하며,
		plist->tail = newNode;				//tail이 가리키는 노드가 새 노드이게끔 갱신//
	}
	plist->numOfData++;		//전체 데이터 수 하나 증가
}

//리스트 조회 함수 정의
int LFirst(List* plist, Data* pdata) {	//첫번째 노드 조회//
	if (plist->tail == NULL)	//리스트에 아무것도 없음
		return FALSE;
	
	plist->before = plist->tail;		//before는 tail이 가리키는 노드(꼬리)를 가리키게 함
	plist->cur = plist->tail->next;		//cur는 tail이 가리키는 노드의 다음(머리)을 가리키게 함

	*pdata = plist->cur->data;			//cur가 가리키는 노드의 데이터 저장
	return TRUE;						//반환 성공
}

int LNext(List* plist, Data* pdata) {	//두번째 이후 노드 조회//
	if (plist->tail == NULL)	//리스트에 아무것도 없음(원형 연결 리스트이므로 리스트의 끝 검사 안함)
		return FALSE;

	plist->before = plist->cur;			//before는 cur가 가리키는 노드를 가리키게 함
	plist->cur = plist->cur->next;		//cur는 원래 가리키던 노드의 다음을 가리키게 함

	*pdata = plist->cur->data;			//cur가 가리키는 노드의 데이터 저장
	return TRUE;						//반환 성공
}

//데이터 삭제 함수 정의
Data LRemove(List* plist) {		 
	Node* rpos = plist->cur;	//현 위치의 cur 노드를 삭제할 노드로 지정 
	Data rdata = rpos->data;	//삭제할 노드의 데이터 저장

	if (rpos == plist->tail) {	//삭제할 노드를 tail이 가리키고 있다면, tail 포인터 조정 필요:
		//즉 원형 연결 리스트는 (포인터를 일관되게 유지하는) 더미 노드가 존재하지 않아 두 경우 고려:
		if (plist->tail == plist->tail->next)	//삭제할 노드가 리스트에 홀로 남은 경우,
			plist->tail = NULL;						//tail 포인터는 NULL을 가리키게 된다
		else									//삭제할 노드를 tail이 가리키는 경우,
			plist->tail = plist->before;			//tail은 삭제될 노드의 이전 노드를 가리키면 된다
	}

	plist->before->next = plist->cur->next;	//before 노드의 다음을 cur 노드의 다음으로 이동
	plist->cur = plist->before;				//cur 노드를 before 노드로 이동

	free(rpos);				//노드 삭제
	plist->numOfData--;		//전체 데이터 수 하나 감소
	return rdata;			//삭제된 노드의 데이터 반환
}

//리스트 데이터 수 확인 함수 정의
int LCount(List* plist) {
	return plist->numOfData;
}