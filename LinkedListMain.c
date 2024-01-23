#include <stdio.h>
#include "LinkedList.h"	//

//���� ������ �����ϱ� ���� �Լ� ����(Main�� ��ġ)	//���޵Ǵ� ������ LData��: typedef int LData;
int WhoIsPrecede(int d1, int d2) {		//�� ������ ���Ͽ� �켱���� ����(��������)
	if (d1 < d2)						//���� �������� �켱���� ����(�������� ������ >�� �����ϸ� ��)
		return 0;	//ù ��° ���� d1�� ���� ������ �ռ��� ���
	else
		return 1;	//�� ��° ���� d2�� ���� ������ �ռ��� ���
}

int main(void) {	//�迭 ��� ���� ����Ʈ�� ���� 
					//(�ٸ� ���� ��� ��� �� �ٸ�: ���⼱ ��带 �Ӹ� �κп� �߰��ϴ� �����̱� ����)
	//����Ʈ ����
	List list;
	int data;

	//����Ʈ �ʱ�ȭ
	ListInit(&list);

	//���� ���� ���� ��� 
	SetSortRule(&list, WhoIsPrecede);

	//������ ����
	LInsert(&list, 11); LInsert(&list, 11); 
	LInsert(&list, 22); LInsert(&list, 22); 
	LInsert(&list, 33);

	//������ ��ȸ �� ���
	printf("���� ������ ��: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//Ư�� �����͵� ����
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}

	//���� �� ���� �����͵� ���
	printf("���� ������ ��: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n");

	return 0;
}