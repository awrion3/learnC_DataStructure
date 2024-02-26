#include <stdio.h>
#include <stdlib.h>			//
#include "LinkedListK.h"	//

//리스트 초기화 함수
void ListInit(List* plist) {
	//더미 노드 생성 후 구조체 멤버인 구조체 포인터 head에 연결: head가 더미 노드를 가리키게 함
	plist->head = (Node*)malloc(sizeof(Node));

	plist->head->next = NULL;	//더미 노드의 멤버 next에 접근하여 연결 안됨으로 초기화

	plist->comp = NULL;			//리스트 정렬 삽입 기준 등록 아직 안함

	plist->numOfData = 0;		//리스트 데이터 수 초기화
}

//데이터 저장 함수
void FInsert(List* plist, LData data) {				//추가1: 정렬 삽입 기준이 없는 경우 머리(더미) 기준으로 삽입
	//새 노드 생성 후 구조체 포인터 newNode에 연결: newNode가 새 노드를 가리키게 함
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;								//새 노드에 데이터 저장

	newNode->next = plist->head->next;	//새 노드는 더미 노드가 가리키던 다음 노드를 가리키게 연결 정정
	plist->head->next = newNode;		//더미 노드는 새 노드를 가리키게 연결 갱신

	plist->numOfData++;									//저장된 데이터 수 하나 증가
}

void SInsert(List* plist, LData data) {				//추가2: 정렬 삽입 기준이 주어진 경우 기준대로
	//새 노드 생성 후 구조체 포인터 newNode에 연결: newNode가 새 노드를 가리키게 함
	Node* newNode = (Node*)malloc(sizeof(Node));
	//한방향(오른쪽) 연결이기에, pred 노드가 더미 노드를 가리키게 연결한다
	Node* pred = plist->head;	//(pred가 가리키는 노드의 오른쪽에만 새 노드 추가 가능하므로)
	newNode->data = data;	//새 노드에 데이터 저장

	//새 노드가 들어갈 위치를 찾기 위한 반복문
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		//pred->next가 존재하고 (pred가 마지막 노드를 가리키지 않고), 정렬 삽입 위치를 찾지 못한 동안,
		//plist->comp(새 데이터와 pred의 다음 노드에 저장된 데 우선순위 비교를 위해 함수 호출:
		//등록 함수 정렬 기준: 첫 인자인 data가 정렬 순서상 앞서서 head에 가까워야 하는 경우 0 반환 == 삽입 위치)
		pred = pred->next;	//pred 노드는 다음 노드로 이동
	}

	newNode->next = pred->next;	//새 노드의 다음을 pred 노드의 다음 노드로 연결 (새 노드 오른쪽 부분 연결)
	pred->next = newNode;		//pred 노드의 다음을 새 노드로 고쳐 연결 (새 노드 왼쪽 부분 연결)

	plist->numOfData++;			//전체 데이터 수 하나 증가
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)		//정렬 삽입 기준이 주어지지 않았다면,
		FInsert(plist, data);		//머리 기준 삼아서 노드 추가
	else
		SInsert(plist, data);		//주어진 기준에 근거하여 노드 추가
}

//리스트 조회 함수
int LFirst(List* plist, LData* pdata) {	//여기서의 첫 노드는 더미 노드에 연결된 노드임에 유의//
	if (plist->head->next == NULL)		//더미 노드가 NULL을 가리키는 경우 저장된 데이터 없음
		return FALSE;
	//그렇지 않은 경우,
	plist->before = plist->head;		//구조체 멤버 before 구조체 노드 포인터를 더미 노드와 연결
	plist->cur = plist->head->next;		//구조체 멤버 cur 구조체 노드 포인터를 첫 노드와 연결

	*pdata = plist->cur->data;		//첫 노드의 데이터를 *pdata에 전달하여 저장
	return TRUE;					//데이터 반환 성공임을 알림
}

int LNext(List* plist, LData* pdata) {	//더미 노드에 연결된 첫 노드가 아닌 두번째부터의 노드들 대상//
	if (plist->cur->next == NULL)		//현재 노드의 다음에 저장된 데이터가 없음
		return FALSE;				//반환할 데이터 없음
	//그렇지 않은 경우
	plist->before = plist->cur;			//구 before 노드를 현 cur 노드가 가리키던 노드로 연결
	plist->cur = plist->cur->next;		//현 cur 노드는 그 다음 노드를 가리키게 연결

	*pdata = plist->cur->data;		//갱신된 현 cur 노드의 데이터를 *pdata에 전달하여 저장
	return TRUE;					//== 데이터 반환 성공
}

//데이터 삭제 함수
LData LRemove(List* plist) {	//조회 함수에서 반환된 데이터가 조건식과 일치 시 데이터 삭제를 위해 호출됨
	Node* rpos = plist->cur;	//현 삭제할 위치를 삭제 노드 포인터에 연결
	LData rdata = rpos->data;	//삭제할 데이터를 저장

	plist->before->next = plist->cur->next;	//이전 노드의 다음 노드 포인터를 현 노드가 가리키던 다음 노드 위치로 수정
	plist->cur = plist->before;		//현 위치 포인터는 다시 한칸 앞으로 이동해 조정 (이전 노드와 같은 노드를 가리킴)
	//(하지만 이전 노드는 이에 따라 추후 자동 조정되므로 조정 불필요)
	free(rpos);				//노드 삭제: 삭제할 노드의 동적할당 해제
	plist->numOfData--;		//전체 데이터 수 하나 감소

	return rdata;			//삭제된 데이터 반환
}

//리스트 데이터 수 확인 함수
int LCount(List* plist) {
	return plist->numOfData;
}

//데이터 정렬 삽입 기준 등록 함수 추가//
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;			//함수 포인터 연결
}