#pragma warning(disable:4996)
#include <stdio.h>
#include "ArrayList.h" //

int main(void) {

	//1// ArrayList의 생성 및 초기화//
	List list;
	int data;	//선언만 하였으므로 쓰레기 값으로 초기화//
	
	ListInit(&list);	//리스트 관련 초기화 (리스트 자체에 저장될 값 관련해서는 초기화 안됨)//

	//2// 5개의 데이터 저장//
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	//3// 저장된 데이터의 수 및 전체 출력//
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {			//첫번째 데이터 조회
		//LFirst 함수 인자 전달로 pdata = &data 연결 및 *pdata = (int형)LData형 배열 첫 원소 값이 저장
		printf("%d ", data);	//간접 참조에 의한 값 저장으로 인해 새롭게 갱신된 data 값 출력 가능//

		while (LNext(&list, &data)) {	//두번째 이후 데이터 조회
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//4// 데이터 중 22를 탐색하여 모두 삭제//
	if (LFirst(&list, &data)) {			//첫번째
		if (data == 22)
			LRemove(&list);			//앞서 LFirst 함수가 참조한 데이터 삭제

		while (LNext(&list, &data))	{	//두번째 이후
			if (data == 22)
				LRemove(&list);		//앞서 LNext 함수가 참조한 데이터 삭제
		}
	}
	printf("\n\n");

	//5// 삭제 후 남은 데이터의 수 및 전체 출력//
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {			//첫번째
		printf("%d ", data);

		while (LNext(&list, &data)) {	//두번째 이후
			printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}