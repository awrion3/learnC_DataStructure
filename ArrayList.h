#ifndef __ARRAY_LIST_H__ //���Ǻ� �������� ���� ��ó�� ������//
#define __ARRAY_LIST_H__

#define TRUE 1			 //��ũ�� ��� ���� ��ó�� ������
#define FALSE 0
#define LIST_LEN 100

#include "DataPoint.h"		//�Ʒ� typedef ���Ǹ� ���� ����//
//typedef int LData;		//����� �����Ǹ� ���� int �ڷ����� LData �ڷ������� ����
typedef Point* LData;		//... ����ü ������ �ڷ����� ...//

//����ü ����
typedef struct ArrayList {	//�迭 ��� ���� ����Ʈ�� ������ ����ü
	LData arr[LIST_LEN];	//����Ʈ�� ���� ����: �迭
	int numOfData;			//���� ������ ��
	int curPosition;		//������ ���� ��ġ ���
} ArrayList;

typedef ArrayList List;	//����� �����Ǹ� ���� ���� ����Ʈ ���� ����ü �ڷ����� List �ڷ������� ����

//�Լ� ���� ����
void ListInit(List *plist);				//����Ʈ �ʱ�ȭ
void LInsert(List *plist, LData data);	//������ ����

int LFirst(List *plist, LData *pdata);	//ù��° ������ ����
int LNext(List *plist, LData *pdata);		//�ι�° ���� ������ ����

LData LRemove(List *plist);				//������ ������ ����
int LCount(List *plist);				//����� ������ �� ��ȯ

#endif					 //���Ǻ� �������� ���� ��ó�� ������//