#include <stdio.h>
#include <stdlib.h>
#include "LinkedListC.h"

//����Ʈ �ʱ�ȭ �Լ� ����
void ListInit(List* plist) {
	plist->tail = NULL;	//������ ���� ���� ����Ʈ(�ϳ��� �����͸�, �Ӹ��� �ƴ� ������ ����Ű�� ��)

	plist->cur = NULL;
	plist->before = NULL;
	
	plist->numOfData = 0;
}

//������ �߰� �Լ� ����
void LInsertFront(List* plist, Data data) {	  //�Ӹ��� ��� �߰��ϴ� �Լ�//
	//�� ��� ���� �� ������ ����
	Node* newNode = (Node*)malloc(sizeof(Node));	
	newNode->data = data;

	if (plist->tail == NULL) {		//tail�� �ƹ��͵� ����Ű�� �ʴ´ٸ�
		plist->tail = newNode;		//�� ��带 ����Ű�� ��
		newNode->next = newNode;	//�� ���� �ڱ��ڽ��� �����Ѿ� ��(���� ���� ����Ʈ�̹Ƿ�)
	}
	else {							//�ι�° ������ �����,
		newNode->next = plist->tail->next;	//������ tail�� next(�Ӹ�) ��带 �� ����� �������� ����
		plist->tail->next = newNode;		//�� ��带 tail�� next(�Ӹ�) ���� ����
	}
	plist->numOfData++;		//��ü ������ �� �ϳ� ����
}

void LInsert(List* plist, Data data) {		//������ ��� �߰��ϴ� �Լ�//
	//�� ��� ���� �� ������ ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {		//tail�� �ƹ��͵� ����Ű�� �ʴ´ٸ�..
		plist->tail = newNode;		//...���� ����
		newNode->next = newNode;	//(ù ���� �� ��ü�� �Ӹ����� �����̱� ����)
	}
	else {							//�ι�° ������ �����,
		newNode->next = plist->tail->next;	//tail�� ����Ű�� ��尡 �߰��� �� ����� ���� ������ ������ ��,
		plist->tail->next = newNode;		//...���� ��������� ���� �����ϸ�,
		plist->tail = newNode;				//tail�� ����Ű�� ��尡 �� ����̰Բ� ����//
	}
	plist->numOfData++;		//��ü ������ �� �ϳ� ����
}

//����Ʈ ��ȸ �Լ� ����
int LFirst(List* plist, Data* pdata) {	//ù��° ��� ��ȸ//
	if (plist->tail == NULL)	//����Ʈ�� �ƹ��͵� ����
		return FALSE;
	
	plist->before = plist->tail;		//before�� tail�� ����Ű�� ���(����)�� ����Ű�� ��
	plist->cur = plist->tail->next;		//cur�� tail�� ����Ű�� ����� ����(�Ӹ�)�� ����Ű�� ��

	*pdata = plist->cur->data;			//cur�� ����Ű�� ����� ������ ����
	return TRUE;						//��ȯ ����
}

int LNext(List* plist, Data* pdata) {	//�ι�° ���� ��� ��ȸ//
	if (plist->tail == NULL)	//����Ʈ�� �ƹ��͵� ����(���� ���� ����Ʈ�̹Ƿ� ����Ʈ�� �� �˻� ����)
		return FALSE;

	plist->before = plist->cur;			//before�� cur�� ����Ű�� ��带 ����Ű�� ��
	plist->cur = plist->cur->next;		//cur�� ���� ����Ű�� ����� ������ ����Ű�� ��

	*pdata = plist->cur->data;			//cur�� ����Ű�� ����� ������ ����
	return TRUE;						//��ȯ ����
}

//������ ���� �Լ� ����
Data LRemove(List* plist) {		 
	Node* rpos = plist->cur;	//�� ��ġ�� cur ��带 ������ ���� ���� 
	Data rdata = rpos->data;	//������ ����� ������ ����

	if (rpos == plist->tail) {	//������ ��带 tail�� ����Ű�� �ִٸ�, tail ������ ���� �ʿ�:
		//�� ���� ���� ����Ʈ�� (�����͸� �ϰ��ǰ� �����ϴ�) ���� ��尡 �������� �ʾ� �� ��� ���:
		if (plist->tail == plist->tail->next)	//������ ��尡 ����Ʈ�� Ȧ�� ���� ���,
			plist->tail = NULL;						//tail �����ʹ� NULL�� ����Ű�� �ȴ�
		else									//������ ��带 tail�� ����Ű�� ���,
			plist->tail = plist->before;			//tail�� ������ ����� ���� ��带 ����Ű�� �ȴ�
	}

	plist->before->next = plist->cur->next;	//before ����� ������ cur ����� �������� �̵�
	plist->cur = plist->before;				//cur ��带 before ���� �̵�

	free(rpos);				//��� ����
	plist->numOfData--;		//��ü ������ �� �ϳ� ����
	return rdata;			//������ ����� ������ ��ȯ
}

//����Ʈ ������ �� Ȯ�� �Լ� ����
int LCount(List* plist) {
	return plist->numOfData;
}