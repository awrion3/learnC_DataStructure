#ifndef __LINKED_LIST_D_H__
#define __LINKED_LIST_D_H__
//(���� ��� ��� ���ϴ� �����, �� ��带 �Ӹ��� �߰��ϴ�) ����� ���� ����Ʈ 
#define TRUE 1
#define FALSE 0

//��� ����
typedef int Data;

typedef struct node {
	Data data;
	struct node* next;	//������ ��� ����Ű�� ������ ����
	struct node* prev;	//���� ��� ����Ű�� ������ ����
} Node;

//����� ���� ����Ʈ ����
typedef struct LinkedListD {
	Node* head;			
	Node* cur;			//������̱⿡ before ������ ������ ����� ������ �ʿ� ����
	int numOfData;
} DLinkedList;

typedef DLinkedList List;

//����� ���� ����Ʈ ���� �Լ�
void ListInit(List* plist);				 //�ʱ�ȭ
void LInsert(List* plist, Data data);	 //����

int LFirst(List* plist, Data* pdata);	 //��ȸ
int LNext(List* plist, Data* pdata);	 //������ ��ȸ
int LPrevious(List* plist, Data* pdata); //���� ��ȸ//

int LCount(List* plist);				 //��
#endif