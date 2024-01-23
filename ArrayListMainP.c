#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		//
#include "ArrayList.h"  
#include "DataPoint.h"  //LData의 자료형 구조체 Point 포인터로 변경하여 정의함에 따라 추가//

int main(void) {

	//1// ArrayList의 생성 및 초기화//
	List list;			//생성

	Point compPos;		//모두 선언만 하였으므로 쓰레기 값으로 초기화//
	Point* ppos;

	ListInit(&list);	//초기화 관련

	//2// 4개의 데이터 저장//
	ppos = (Point*)malloc(sizeof(Point));	//구조체 하나 동적할당
	SetPointPos(ppos, 2, 1);	//구조체 멤버 값 구조체에 저장
	LInsert(&list, ppos);		//구조체 주소 값 리스트에 저장

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	//3// 저장된 데이터의 수 및 전체 출력//
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {			//첫번째 데이터 조회
		ShowPointPos(ppos);		//참조된 데이터 출력

		while (LNext(&list, &ppos)) {	//두번째 이후 데이터 조회
			ShowPointPos(ppos);	//참조된 데이터 출력
		}
	}
	printf("\n\n");

	//4// 데이터 중 xpos = 2인 데이터를 모두 삭제//
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {			//첫번째
		if (PointComp(ppos, &compPos) == 1)	{ //xpos가 같은 경우
			ppos = LRemove(&list);			//앞서 LFirst 함수가 참조한 데이터 삭제
			free(ppos);					//삭제된 해당 구조체 동적할당 해제
		}

		while (LNext(&list, &ppos)) {	//두번째 이후
			if (PointComp(ppos, &compPos) == 1) { //xpos가 같은 경우
				ppos = LRemove(&list);			//... 및 반환된 해당 구조체 데이터의 주소값 저장
				free(ppos);				//삭제된 해당 구조체 동적할당 해제
			}
		}
	}
	printf("\n\n");

	//5// 삭제 후 남은 데이터의 수 및 전체 출력//
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {			//첫번째 데이터 조회
		ShowPointPos(ppos);		//참조된 데이터 출력

		while (LNext(&list, &ppos)) {	//두번째 이후 데이터 조회
			ShowPointPos(ppos);	//참조된 데이터 출력
		}
	}
	printf("\n\n");

	return 0;
}