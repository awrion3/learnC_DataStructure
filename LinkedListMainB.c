#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>	//

typedef struct node {
	int data;
	struct node* next;	//�ڱ� ���� ����ü(���� ����ü �ڷ����� �����ʹ� �ش� ����ü�� ����� ����)
} Node;					

int main(void) {

	Node* head = NULL;	//����Ʈ�� �Ӹ��� ����ų ����ü ������
	Node* tail = NULL;	//����Ʈ�� ������ ����ų ����ü ������
	Node* cur = NULL;	//����� �������� ��ȸ�� ���� ����ü ������

	Node* newNode = NULL;	//�� ����� ������ ���� ����ü ������
	int readData;

	//������ �Է�
	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);		//������ �Է¹ް� ���� �Ҹ��� �� �ݺ� ����
		if (readData < 1)
			break;

		//��� �߰�
		newNode = (Node*)malloc(sizeof(Node));	//�� ����ü ��� �����Ҵ� �ޱ�
		newNode->data = readData;	//�Է��� ������ (����ü ��� data��) ����
		newNode->next = NULL;		//����ü ��� next�� ��� �ƹ��͵� �Ȱ���Ű�� ��

		if (head == NULL)			//ù��° ����� ���, head�� ����Ű�� ��
			head = newNode;
		else						//�ι�° ���� �����ʹ�, 1)�� ���� ���� ����� next�� newNode�� ����Ű�� ��
			tail->next = newNode;

		tail = newNode;				//���� �߰��� ���� �����Ͽ� ����Ʈ�� ���� tail�� ����Ű�� ��1)
	}
	printf("\n");

	//������ ���
	printf("�Է� ���� �������� ��ü ���:\n");
	if (head == NULL)							//����Ʈ�� ����� �����Ͱ� ���� ���
		printf("����� �ڿ����� �����ϴ�!\n");
	else {										//��ȸ�� ���� cur ����ü ������ ���//
		cur = head;						//ù��° ��带 ����Ű���� ���� �ʱ�ȭ�ϰ�,
		printf("%d ", cur->data);		//�ش� ����ü ��忡 �����Ͽ� ��� data ���

		while (cur->next != NULL) {	//����ü�� ��� next�� NULL�� �ƴ� ���� (����� ���� ������ �����)
			cur = cur->next;			//���� ����ü ���� ���� �����ϰ�,
			printf("%d ", cur->data);	//... ���
		}
	}
	printf("\n\n");

	//������ ���� �� �޸� ����
	if (head == NULL) {				//����Ʈ�� �����Ͱ� ���� ���
		return 0;					//������ ��尡 �������� �����Ƿ� ���α׷� ����
	}
	else {							//����Ʈ�� �����Ͱ� �ִ� ���
		Node* delNode = head;				//������ ���� ����ü ������ �����Ͽ� ù ����ü ���� ����
		Node* delNextNode = head->next;		//�� �ٸ� ����ü �����ʹ� ������ ����� ���� ���� ����

		printf("%d ���� ����!\n", head->data);
		free(delNode);						//�����Ҵ�(�޸� ����) ������ ���� �ش� ����ü ��� ����

		while (delNextNode != NULL) {		//���� ��尡 �����ϴ� ���
			delNode = delNextNode;				//������ ���� ����
			delNextNode = delNextNode->next;	//�� ���� ���� ����

			printf("%d ����...\n", delNode->data);
			free(delNode);					//���� �ݺ� ����
		}	//�ٸ�, head�� ������ ����� ���� ��带 ����Ű�Բ� ���ŵǾ�� �ϴµ�, ���⼱ �̱���.*//
	}

	return 0;
}