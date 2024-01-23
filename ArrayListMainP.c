#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		//
#include "ArrayList.h"  
#include "DataPoint.h"  //LData�� �ڷ��� ����ü Point �����ͷ� �����Ͽ� �����Կ� ���� �߰�//

int main(void) {

	//1// ArrayList�� ���� �� �ʱ�ȭ//
	List list;			//����

	Point compPos;		//��� ���� �Ͽ����Ƿ� ������ ������ �ʱ�ȭ//
	Point* ppos;

	ListInit(&list);	//�ʱ�ȭ ����

	//2// 4���� ������ ����//
	ppos = (Point*)malloc(sizeof(Point));	//����ü �ϳ� �����Ҵ�
	SetPointPos(ppos, 2, 1);	//����ü ��� �� ����ü�� ����
	LInsert(&list, ppos);		//����ü �ּ� �� ����Ʈ�� ����

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	//3// ����� �������� �� �� ��ü ���//
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {			//ù��° ������ ��ȸ
		ShowPointPos(ppos);		//������ ������ ���

		while (LNext(&list, &ppos)) {	//�ι�° ���� ������ ��ȸ
			ShowPointPos(ppos);	//������ ������ ���
		}
	}
	printf("\n\n");

	//4// ������ �� xpos = 2�� �����͸� ��� ����//
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {			//ù��°
		if (PointComp(ppos, &compPos) == 1)	{ //xpos�� ���� ���
			ppos = LRemove(&list);			//�ռ� LFirst �Լ��� ������ ������ ����
			free(ppos);					//������ �ش� ����ü �����Ҵ� ����
		}

		while (LNext(&list, &ppos)) {	//�ι�° ����
			if (PointComp(ppos, &compPos) == 1) { //xpos�� ���� ���
				ppos = LRemove(&list);			//... �� ��ȯ�� �ش� ����ü �������� �ּҰ� ����
				free(ppos);				//������ �ش� ����ü �����Ҵ� ����
			}
		}
	}
	printf("\n\n");

	//5// ���� �� ���� �������� �� �� ��ü ���//
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {			//ù��° ������ ��ȸ
		ShowPointPos(ppos);		//������ ������ ���

		while (LNext(&list, &ppos)) {	//�ι�° ���� ������ ��ȸ
			ShowPointPos(ppos);	//������ ������ ���
		}
	}
	printf("\n\n");

	return 0;
}