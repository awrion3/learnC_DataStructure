#pragma warning(disable:4996)
#include <stdio.h>
#include "ArrayList.h" //

int main(void) {

	//1// ArrayList�� ���� �� �ʱ�ȭ//
	List list;
	int data;	//���� �Ͽ����Ƿ� ������ ������ �ʱ�ȭ//
	
	ListInit(&list);	//����Ʈ ���� �ʱ�ȭ (����Ʈ ��ü�� ����� �� �����ؼ��� �ʱ�ȭ �ȵ�)//

	//2// 5���� ������ ����//
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	//3// ����� �������� �� �� ��ü ���//
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {			//ù��° ������ ��ȸ
		//LFirst �Լ� ���� ���޷� pdata = &data ���� �� *pdata = (int��)LData�� �迭 ù ���� ���� ����
		printf("%d ", data);	//���� ������ ���� �� �������� ���� ���Ӱ� ���ŵ� data �� ��� ����//

		while (LNext(&list, &data)) {	//�ι�° ���� ������ ��ȸ
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//4// ������ �� 22�� Ž���Ͽ� ��� ����//
	if (LFirst(&list, &data)) {			//ù��°
		if (data == 22)
			LRemove(&list);			//�ռ� LFirst �Լ��� ������ ������ ����

		while (LNext(&list, &data))	{	//�ι�° ����
			if (data == 22)
				LRemove(&list);		//�ռ� LNext �Լ��� ������ ������ ����
		}
	}
	printf("\n\n");

	//5// ���� �� ���� �������� �� �� ��ü ���//
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {			//ù��°
		printf("%d ", data);

		while (LNext(&list, &data)) {	//�ι�° ����
			printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}