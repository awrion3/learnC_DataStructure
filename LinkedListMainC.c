#include <stdio.h>
#include "LinkedListC.h"	//

int main(void) {

	//원형 연결 리스트의 생성 및 초기화
	List list;
	int data, nodeNum;
	
	ListInit(&list);

	//리스트에 데이터 5개 저장
	LInsert(&list, 3); LInsert(&list, 4); LInsert(&list, 5);
	LInsertFront(&list, 2); LInsertFront(&list, 1);

	//리스트에 저장된 데이터를 연속 3회 출력 (조회에 있어 원형 연결이기에 while문이 아닌 for문 사용)
	if (LFirst(&list, &data)) {	//+1회
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) * 3 - 1; i++) {	//0 ~ < 5 * 3 - 1 = 14 == +14회
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	//2의 배수를 찾아서 해당 데이터 모두 삭제
	nodeNum = LCount(&list);

	if (nodeNum != 0) {	//노드 개수가 0이 아니라면

		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (int i = 0; i < nodeNum - 1; i++) {	//위에서 1번 조회했으므로, -1
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	//전체 리스트 1회 출력
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) - 1; i++)	//위에서 1번 조회했으므로, -1
			if (LNext(&list, &data))
				printf("%d ", data);
	}

	return 0;
}