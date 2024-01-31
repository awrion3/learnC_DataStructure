#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;		 //������ Ÿ��

typedef struct node {	 //���� ����Ʈ(�����) ���
	Data data;
	struct node* next;
	struct node* prev;
} Node;

typedef struct dlDeque { //����� ����Ʈ ��� �� ����
	Node* head;
	Node* tail;
} DLDeque;

typedef DLDeque Deque;

//�Լ� ���� ����
void DequeInit(Deque* pdeq);	//�ʱ�ȭ �� ���� Ȯ��
int DQIsEmpty(Deque* pdeq);

void DQAddFirst(Deque* pdeq, Data data);	//������ �ֱ�
void DQAddLast(Deque* pdeq, Data data);

Data DQRemoveFirst(Deque* pdeq);			//������ ����
Data DQRemoveLast(Deque* pdeq);

Data DQGetFirst(Deque* pdeq);	//������ ����
Data DQGetLast(Deque* pdeq);
#endif