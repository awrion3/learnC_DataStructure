#include <stdio.h>
#include "ArrayList.h"	//

//��: ����ü �����Ͱ� ����Ű�� ����ü�� ��� ����:  ->  ==  *().
//1//����Ʈ �ʱ�ȭ �Լ� ����
void ListInit(List* plist) {	
	plist->numOfData = 0;		//����Ʈ�� ����� ������ �� 0
	plist->curPosition = -1;	//���� �ƹ� ��ġ�� ����Ű�� ����
}

//2//������ ���� �Լ� ����
void LInsert(List* plist, LData data) {
	if (plist->numOfData >= LIST_LEN){	//�ε����� �迭 ���̿� ���ų� ũ�� ���� �Ұ�
		puts("������ �Ұ��մϴ�!"); 	//���� ���� �ڵ� ���
		return;	//�Լ� ���Ḧ ���� ���
	}

	//plist->numOfData �ε��� ����Ͽ� plist->arr[�ε���]�� ������ ����
	plist->arr[plist->numOfData] = data;
	//����� ������ �� ����
	plist->numOfData++;
}

//3//����Ʈ ��ȸ �Լ� ����
//3-1//ù��° ������ ���� �Լ�
int LFirst(List* plist, LData *pdata) {
	if (plist->numOfData == 0)	//����� �����Ͱ� ���� ��� FALSE ��ȯ
		return FALSE;

	//���� ��ġ �ʱ�ȭ
	plist->curPosition = 0;		
	//LData�� pdata �����Ͱ� ����Ű�� ������ List ����ü�� ����� LData�� �迭�� ù ��° ���Ұ� ����
	*pdata = plist->arr[0];
	return TRUE;	//����� �����Ͱ� �ִ� ��� TRUE ��ȯ
}
//3-2//�ι�° ���� ������ ���� �Լ�
int LNext(List* plist, LData *pdata) {
	if (plist->curPosition >= plist->numOfData - 1)	//�� �ε����� ����� ������ �� -1���� ���ų� ũ��
		return FALSE;								//���� �����ʹ� ���� ���̹Ƿ� FALSE ��ȯ

	//���� �����Ͱ� �ִٸ�
	plist->curPosition++;	//���� �����ͷ� �ε��� ������Ű��
	//�̵��� �ε�����, �� ���� �������� �� ����
	*pdata = plist->arr[plist->curPosition];	
	return TRUE;	//���� �����Ͱ� �־��� ��� TRUE ��ȯ
}

//4//������ ���� �Լ� ����
LData LRemove(List* plist) {
	int rpos = plist->curPosition;	//������ �������� �ε��� ����
	int num = plist->numOfData;
	
	LData rdata = plist->arr[rpos];	//������ ������ ����

	for (int i = rpos; i < num - 1; i++)	//�ε��� ������ ������ ������ ���� ������ ��ĭ�� ������ �̵�
		plist->arr[i] = plist->arr[i + 1];

	plist->numOfData--;			//��ü ������ �� �� �� ����
	plist->curPosition--;		//������ ��ġ�� �� ĭ ������ �ٽ� �̵�

	return rdata;					//������ ������ ��ȯ
}

//5//����Ʈ �� ������ �� Ȯ�� �Լ� ����
int LCount(List* plist) {
	return plist->numOfData;	//��ü ������ �� ��ȯ	
}