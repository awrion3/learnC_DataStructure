#include <stdio.h>
#include "ArrayList.h"	//

//팁: 구조체 포인터가 가리키는 구조체의 멤버 접근:  ->  ==  *().
//1//리스트 초기화 함수 정의
void ListInit(List* plist) {	
	plist->numOfData = 0;		//리스트에 저장된 데이터 수 0
	plist->curPosition = -1;	//현재 아무 위치도 가리키지 않음
}

//2//데이터 저장 함수 정의
void LInsert(List* plist, LData data) {
	if (plist->numOfData >= LIST_LEN){	//인덱스가 배열 길이와 같거나 크면 저장 불가
		puts("저장이 불가합니다!"); 	//개행 문자 자동 출력
		return;	//함수 종료를 위해 사용
	}

	//plist->numOfData 인덱스 사용하여 plist->arr[인덱스]에 데이터 저장
	plist->arr[plist->numOfData] = data;
	//저장된 데이터 수 증가
	plist->numOfData++;
}

//3//리스트 조회 함수 정의
//3-1//첫번째 데이터 참조 함수
int LFirst(List* plist, LData *pdata) {
	if (plist->numOfData == 0)	//저장된 데이터가 없는 경우 FALSE 반환
		return FALSE;

	//참조 위치 초기화
	plist->curPosition = 0;		
	//LData형 pdata 포인터가 가리키는 공간에 List 구조체의 멤버인 LData형 배열의 첫 번째 원소값 저장
	*pdata = plist->arr[0];
	return TRUE;	//저장된 데이터가 있는 경우 TRUE 반환
}
//3-2//두번째 이후 데이터 참조 함수
int LNext(List* plist, LData *pdata) {
	if (plist->curPosition >= plist->numOfData - 1)	//현 인덱스가 저장된 데이터 수 -1보다 같거나 크면
		return FALSE;								//다음 데이터는 없는 것이므로 FALSE 반환

	//다음 데이터가 있다면
	plist->curPosition++;	//다음 데이터로 인덱스 증가시키기
	//이동한 인덱스의, 즉 다음 데이터의 값 저장
	*pdata = plist->arr[plist->curPosition];	
	return TRUE;	//다음 데이터가 있었던 경우 TRUE 반환
}

//4//데이터 삭제 함수 정의
LData LRemove(List* plist) {
	int rpos = plist->curPosition;	//삭제할 데이터의 인덱스 저장
	int num = plist->numOfData;
	
	LData rdata = plist->arr[rpos];	//삭제할 데이터 저장

	for (int i = rpos; i < num - 1; i++)	//인덱스 범위에 유의해 삭제를 위해 데이터 한칸씩 앞으로 이동
		plist->arr[i] = plist->arr[i + 1];

	plist->numOfData--;			//전체 데이터 수 한 개 감소
	plist->curPosition--;		//참조할 위치도 한 칸 앞으로 다시 이동

	return rdata;					//삭제된 데이터 반환
}

//5//리스트 내 데이터 수 확인 함수 정의
int LCount(List* plist) {
	return plist->numOfData;	//전체 데이터 수 반환	
}