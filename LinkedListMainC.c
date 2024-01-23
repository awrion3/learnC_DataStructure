#include <stdio.h>
#include "LinkedListC.h"	//

int main(void) {

	//���� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data, nodeNum;
	
	ListInit(&list);

	//����Ʈ�� ������ 5�� ����
	LInsert(&list, 3); LInsert(&list, 4); LInsert(&list, 5);
	LInsertFront(&list, 2); LInsertFront(&list, 1);

	//����Ʈ�� ����� �����͸� ���� 3ȸ ��� (��ȸ�� �־� ���� �����̱⿡ while���� �ƴ� for�� ���)
	if (LFirst(&list, &data)) {	//+1ȸ
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) * 3 - 1; i++) {	//0 ~ < 5 * 3 - 1 = 14 == +14ȸ
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	//2�� ����� ã�Ƽ� �ش� ������ ��� ����
	nodeNum = LCount(&list);

	if (nodeNum != 0) {	//��� ������ 0�� �ƴ϶��

		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (int i = 0; i < nodeNum - 1; i++) {	//������ 1�� ��ȸ�����Ƿ�, -1
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	//��ü ����Ʈ 1ȸ ���
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		for (int i = 0; i < LCount(&list) - 1; i++)	//������ 1�� ��ȸ�����Ƿ�, -1
			if (LNext(&list, &data))
				printf("%d ", data);
	}

	return 0;
}