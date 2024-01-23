#include <stdio.h>
#include "LinkedList.h"	//

//정렬 기준을 설정하기 위한 함수 정의(Main에 위치)	//전달되는 실인자 LData형: typedef int LData;
int WhoIsPrecede(int d1, int d2) {		//두 데이터 비교하여 우선순위 결정(오름차순)
	if (d1 < d2)						//값이 작을수록 우선순위 높음(내림차순 정렬은 >로 변경하면 됨)
		return 0;	//첫 번째 인자 d1이 정렬 순서상 앞서는 경우
	else
		return 1;	//두 번째 인자 d2가 정렬 순서상 앞서는 경우
}

int main(void) {	//배열 기반 순차 리스트와 동일 
					//(다만 실행 결과 출력 시 다름: 여기선 노드를 머리 부분에 추가하는 형식이기 때문)
	//리스트 생성
	List list;
	int data;

	//리스트 초기화
	ListInit(&list);

	//정렬 삽입 기준 등록 
	SetSortRule(&list, WhoIsPrecede);

	//데이터 저장
	LInsert(&list, 11); LInsert(&list, 11); 
	LInsert(&list, 22); LInsert(&list, 22); 
	LInsert(&list, 33);

	//데이터 조회 및 출력
	printf("현재 데이터 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//특정 데이터들 삭제
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}

	//삭제 후 남은 데이터들 출력
	printf("현재 데이터 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n");

	return 0;
}