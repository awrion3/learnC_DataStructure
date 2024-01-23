#include <stdio.h>
#include <stdlib.h>
#include "LinkedListD.h"

//����Ʈ �ʱ�ȭ �Լ� ����
void ListInit(List* plist) {
	plist->head = NULL;		//����� ���� ����Ʈ�̹Ƿ� plist->before�� ���ʿ�
	plist->numOfData = 0;
}

//��� ���� �Լ� ����
void LInsert(List* plist, Data data) {
	//�� ��� ���� �� ������ ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	//ù ����� ���: �� ����� ������ NULL�� �ʱ�ȭ 
	//�ι�° ���� ����� ���: �� ����� ������ ���� ���� �ʱ�ȭ
	newNode->next = plist->head;

	if (plist->head != NULL)			//ù��° ��� �߰��� �ƴ� ���,
		plist->head->prev = newNode;	//���� ����� ������ �� ���� ����(����� ����)

	//�� ����� ������ NULL�� �ʱ�ȭ
	newNode->prev = NULL;
	//������ head�� �� ��带 ����Ű�� ����
	plist->head = newNode;

	plist->numOfData++;	//��ü ������ �� �ϳ� ����
}

//����Ʈ ��ȸ �Լ� ����
int LFirst(List* plist, Data* pdata) {		//ù ��° ��� ������ ��ȸ
	if (plist->head == NULL)	//��尡 ���� ��� FALSE ��ȯ
		return FALSE;

	plist->cur = plist->head;	//cur�� ù ��带 ����Ű�� ��
	
	*pdata = plist->cur->data;	//������ ��ȯ ����
	return TRUE;
}

int LNext(List* plist, Data* pdata) {		//�� ��° ������ ��� ������ ��ȸ
	if (plist->cur->next == NULL)	//���� ��尡 ���� ��� FALSE ��ȯ
		return FALSE;

	plist->cur = plist->cur->next;	//cur�� ���� ��带 ����Ű�� ��

	*pdata = plist->cur->data;		//������ ��ȯ ����
	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {	//LNext�� �ݴ� �������� ������ ��ȸ
	if (plist->cur->prev == NULL)	//���� ��尡 ���� ��� FALSE ��ȯ
		return FALSE;

	plist->cur = plist->cur->prev;	//cur�� ���� ��带 ����Ű�� ��

	*pdata = plist->cur->data;		//������ ��ȯ ����
	return TRUE;
}

//������ �� Ȯ�� �Լ� ����
int LCount(List* plist) {
	return plist->numOfData;	//��ü ������ �� ��ȯ
}