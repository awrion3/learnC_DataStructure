#ifndef __LINKED_LIST_K_H__
#define __LINKED_LIST_K_H__		//���� ��� ��� �ܹ��� ���� ����Ʈ ��Ȱ��

#define TRUE 1				//��ũ�� ��� ���� ��ó�� ������
#define FALSE 0

//�� ����
typedef int LData;			//int���� LData �ڷ������� ����

//����ü ����
typedef struct node {		//�����Ҵ� ��� ���� ����Ʈ�� �����ϱ� ���� ��� ����ü
	LData data;				//����Ʈ ������ ����
	struct node* next;		//���� �����͸� ������ ����ü�� ����
} Node;

typedef struct linkedList {	//���� ����Ʈ�� ������ ����ü
	//���� ����Ʈ�� ���� ��带 ����Ű�� ����ü ������
	Node* head;
	//���� ����Ʈ�� ����/������ ���� ����ü ������
	Node* before;
	Node* cur;				  //��� Main�� �������� ����: �ټ��� ����Ʈ �ڷᱸ���� ���)

	int numOfData;						//��ü ������ �� ���
	int (*comp)(LData d1, LData d2);	//���� ���� ���
} LinkedList;

typedef LinkedList List;	//���� ����Ʈ ���� ����ü �ڷ����� List������ ������

//�Լ� ���� ����
void ListInit(List* plist);				//����Ʈ �ʱ�ȭ
void LInsert(List* plist, LData data);	//������ ����

int LFirst(List* plist, LData* pdata);	//ù��° ������ ����
int LNext(List* plist, LData* pdata);	//�ι�° ���� ������ ����

LData LRemove(List* plist);				//������ ������ ����
int LCount(List* plist);				//����� ������ �� ��ȯ

//���� ���� ���� ��� �Լ� �߰�//
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));
#endif
