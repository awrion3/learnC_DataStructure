#include <stdio.h>
#include <stdlib.h>		//
#include "LinkedList.h"	//

//����Ʈ �ʱ�ȭ �Լ�
void ListInit(List* plist) {
	//���� ��� ���� �� ����ü ����� ����ü ������ head�� ����: head�� ���� ��带 ����Ű�� ��
	plist->head = (Node*)malloc(sizeof(Node));	 

	plist->head->next = NULL;	//���� ����� ��� next�� �����Ͽ� ���� �ȵ����� �ʱ�ȭ

	plist->comp = NULL;			//����Ʈ ���� ���� ���� ��� ���� ����

	plist->numOfData = 0;		//����Ʈ ������ �� �ʱ�ȭ
}

//������ ���� �Լ�
void FInsert(List* plist, LData data) {				//�߰�1: ���� ���� ������ ���� ��� �Ӹ�(����) �������� ����
	//�� ��� ���� �� ����ü ������ newNode�� ����: newNode�� �� ��带 ����Ű�� ��
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;								//�� ��忡 ������ ����

	newNode->next = plist->head->next;	//�� ���� ���� ��尡 ����Ű�� ���� ��带 ����Ű�� ���� ����
	plist->head->next = newNode;		//���� ���� �� ��带 ����Ű�� ���� ����

	plist->numOfData++;									//����� ������ �� �ϳ� ����
}

void SInsert(List* plist, LData data) {				//�߰�2: ���� ���� ������ �־��� ��� ���ش��
	//�� ��� ���� �� ����ü ������ newNode�� ����: newNode�� �� ��带 ����Ű�� ��
	Node* newNode = (Node*)malloc(sizeof(Node));	
	//�ѹ���(������) �����̱⿡, pred ��尡 ���� ��带 ����Ű�� �����Ѵ�
	Node* pred = plist->head;	//(pred�� ����Ű�� ����� �����ʿ��� �� ��� �߰� �����ϹǷ�)
	newNode->data = data;	//�� ��忡 ������ ����

	//�� ��尡 �� ��ġ�� ã�� ���� �ݺ���
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		//pred->next�� �����ϰ� (pred�� ������ ��带 ����Ű�� �ʰ�), ���� ���� ��ġ�� ã�� ���� ����,
		//plist->comp(�� �����Ϳ� pred�� ���� ��忡 ����� ���� �켱���� �񱳸� ���� �Լ� ȣ��:
		//��� �Լ� ���� ����: ù ������ data�� ���� ������ �ռ��� head�� ������� �ϴ� ��� 0 ��ȯ == ���� ��ġ)
		pred = pred->next;	//pred ���� ���� ���� �̵�
	}

	newNode->next = pred->next;	//�� ����� ������ pred ����� ���� ���� ���� (�� ��� ������ �κ� ����)
	pred->next = newNode;		//pred ����� ������ �� ���� ���� ���� (�� ��� ���� �κ� ����)

	plist->numOfData++;			//��ü ������ �� �ϳ� ����
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)		//���� ���� ������ �־����� �ʾҴٸ�,
		FInsert(plist, data);		//�Ӹ� ���� ��Ƽ� ��� �߰�
	else
		SInsert(plist, data);		//�־��� ���ؿ� �ٰ��Ͽ� ��� �߰�
}

//����Ʈ ��ȸ �Լ�
int LFirst(List* plist, LData *pdata) {	//���⼭�� ù ���� ���� ��忡 ����� ����ӿ� ����//
	if (plist->head->next == NULL)		//���� ��尡 NULL�� ����Ű�� ��� ����� ������ ����
		return FALSE;
	//�׷��� ���� ���,
	plist->before = plist->head;		//����ü ��� before ����ü ��� �����͸� ���� ���� ����
	plist->cur = plist->head->next;		//����ü ��� cur ����ü ��� �����͸� ù ���� ����

	*pdata = plist->cur->data;		//ù ����� �����͸� *pdata�� �����Ͽ� ����
	return TRUE;					//������ ��ȯ �������� �˸�
}

int LNext(List* plist, LData* pdata) {	//���� ��忡 ����� ù ��尡 �ƴ� �ι�°������ ���� ���//
	if (plist->cur->next == NULL)		//���� ����� ������ ����� �����Ͱ� ����
		return FALSE;				//��ȯ�� ������ ����
	//�׷��� ���� ���
	plist->before = plist->cur;			//�� before ��带 �� cur ��尡 ����Ű�� ���� ����
	plist->cur = plist->cur->next;		//�� cur ���� �� ���� ��带 ����Ű�� ����

	*pdata = plist->cur->data;		//���ŵ� �� cur ����� �����͸� *pdata�� �����Ͽ� ����
	return TRUE;					//== ������ ��ȯ ����
}

//������ ���� �Լ�
LData LRemove(List* plist) {	//��ȸ �Լ����� ��ȯ�� �����Ͱ� ���ǽİ� ��ġ �� ������ ������ ���� ȣ���
	Node* rpos = plist->cur;	//�� ������ ��ġ�� ���� ��� �����Ϳ� ����
	LData rdata = rpos->data;	//������ �����͸� ����

	plist->before->next = plist->cur->next;	//���� ����� ���� ��� �����͸� �� ��尡 ����Ű�� ���� ��� ��ġ�� ����
	plist->cur = plist->before;		//�� ��ġ �����ʹ� �ٽ� ��ĭ ������ �̵��� ���� (���� ���� ���� ��带 ����Ŵ)
									//(������ ���� ���� �̿� ���� ���� �ڵ� �����ǹǷ� ���� ���ʿ�)
	free(rpos);				//��� ����: ������ ����� �����Ҵ� ����
	plist->numOfData--;		//��ü ������ �� �ϳ� ����

	return rdata;			//������ ������ ��ȯ
}

//����Ʈ ������ �� Ȯ�� �Լ�
int LCount(List* plist) {
	return plist->numOfData;
}

//������ ���� ���� ���� ��� �Լ� �߰�//
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;			//�Լ� ������ ����
}