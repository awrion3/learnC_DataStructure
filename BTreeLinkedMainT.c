#include <stdio.h>
#include "BTreeLinkedT.h"	//

//�Լ� ���� ����
void ShowIntData(int data);	//��� �湮�ؼ� �� ���� ����

int main(void) {

	//��� ���� �� �ʱ�ȭ
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	//��忡 ������ ����
	SetData(bt1, 1); SetData(bt2, 2); 
	SetData(bt3, 3); SetData(bt4, 4);
	SetData(bt5, 5); SetData(bt6, 6);

	//���� Ʈ�� ����
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeLeftSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);

	//Ʈ�� ��ȸ �� ���
	PreorderTraverse(bt1, ShowIntData);		//����
	printf("\n");
	InorderTraverse(bt1, ShowIntData);		//����
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);	//���� ��ȸ
	printf("\n");

	return 0;
}

//�Լ� ����: ��� �����Ͽ� ����ϴ� ���� ����
void ShowIntData(int data) {
	printf("%d ", data);
}