#ifndef __LINKED_LIST_C_H__
#define __LINKED_LIST_C_H__
//���� ���� ����Ʈ: �ܼ� ���� ����Ʈ�� �޸� �Ӹ��� ������ ����Ű�� ������ ���� ���� ���� �ʾƵ� �ȴ�
//�ϳ��� ������ ������ �־ �Ӹ� �Ǵ� ������ ��带 �߰��� �� �ִ�
#define TRUE 1
#define FALSE 0

//��� ���� ����ü ����
typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
} Node;

//������ ���� ���� ����Ʈ: �ϳ��� ������ ������ �Ӹ��� �ƴ� ������ ����Ű�� �Ѵ�
//tail == ������ ����Ű�� ������ ����, tail->next == �Ӹ��� ����Ű�� ������ ����
typedef struct CLL {
	Node* tail;

	Node* cur;
	Node* before;

	int numOfData;
} CList;

typedef CList List;

//�Լ� ���� ����
void ListInit(List* plist);

void LInsert(List* plsit, Data data);		//������ ��� �߰�
void LInsertFront(List* plist, Data data);	//�Ӹ��� ��� �߰�

int LFirst(List* plsit, Data* pdata);
int LNext(List* plist, Data* pdata);	//����Ʈ ���� ������ ���, ù ������ �ٽ� ��ȸ�� ���۵ǰ� ����

Data LRemove(List* plist);
int LCount(List* plist);

#endif