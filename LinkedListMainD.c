#include <stdio.h>
#include "LinkedListD.h"

int main(void) {

	//����� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list; int data;
	
	ListInit(&list);

	//8���� ������ ����
	LInsert(&list, 1); LInsert(&list, 2); LInsert(&list, 3); LInsert(&list, 4); 
	LInsert(&list, 5); LInsert(&list, 6); LInsert(&list, 7); LInsert(&list, 8);

	//����� ������ ��ȸ
	if (LFirst(&list, &data)) {
		printf("%d ", data);			//(8���)

		while (LNext(&list, &data)) {	  //������ ���� �̵��ϸ� ��ȸ
			printf("%d ", data);		//(7...1���)
		}

		while (LPrevious(&list, &data)) {	//���� ���� �̵��ϸ� ��ȸ
			printf("%d ", data);		//(2...8���)
		}
		printf("\n");
	}

	return 0;
}