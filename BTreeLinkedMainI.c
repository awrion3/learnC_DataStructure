#include <stdio.h>
#include "BTreeLinked.h"	//

//���� ��ȸ(�� ����->��Ʈ->�� ����)�� ���� ���� Ʈ�� ����
void InorderTraverse(BTreeNode* bt) {
	if (bt == NULL)			//��尡 �������̸� ��ȸ ����
		return;

	InorderTraverse(bt->left);	//���� ���� Ʈ���� ��ȸ
	printf("%d \n", bt->data);	//��Ʈ ��� �湮
	InorderTraverse(bt->right);	//������ ���� Ʈ���� ��ȸ
	//Preorder���� Postorder���� ��ȸ�� �� ���� ������ ����
}

int main(void) {

	//��� ���� �� �ʱ�ȭ
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	//��忡 ������ ����
	SetData(bt1, 1);
	SetData(bt2, 2); SetData(bt3, 3);
	SetData(bt4, 4);

	//���� Ʈ�� ����
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	//��ü ������ ���//
	InorderTraverse(bt1);

	return 0;
}