#ifndef __ARRAY_LIST_H__ //조건부 컴파일을 위한 전처리 지시자//
#define __ARRAY_LIST_H__

#define TRUE 1			 //매크로 상수 정의 전처리 지시자
#define FALSE 0
#define LIST_LEN 100

#include "DataPoint.h"		//아래 typedef 정의를 위해 포함//
//typedef int LData;		//사용자 형정의를 통해 int 자료형을 LData 자료형으로 정의
typedef Point* LData;		//... 구조체 포인터 자료형을 ...//

//구조체 정의
typedef struct ArrayList {	//배열 기반 순차 리스트를 정의한 구조체
	LData arr[LIST_LEN];	//리스트의 저장 공간: 배열
	int numOfData;			//저장 데이터 수
	int curPosition;		//데이터 참조 위치 기록
} ArrayList;

typedef ArrayList List;	//사용자 형정의를 통해 순차 리스트 관련 구조체 자료형을 List 자료형으로 정의

//함수 원형 선언
void ListInit(List *plist);				//리스트 초기화
void LInsert(List *plist, LData data);	//데이터 저장

int LFirst(List *plist, LData *pdata);	//첫번째 데이터 참조
int LNext(List *plist, LData *pdata);		//두번째 이후 데이터 참조

LData LRemove(List *plist);				//참조한 데이터 삭제
int LCount(List *plist);				//저장된 데이터 수 반환

#endif					 //조건부 컴파일을 위한 전처리 지시자//