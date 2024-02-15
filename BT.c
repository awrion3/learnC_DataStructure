#include <stdio.h>
#include <stdlib.h>
#include "BT.h"	//BTreeLinkedT.h�� ����
//�Լ� ����

//��� ���� �� �ʱ�ȭ
BTreeNode* MakeBTreeNode(void) {
	//��� ����
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	//��� �ʱ�ȭ
	nd->left = NULL;
	nd->right = NULL;
	//��� �ּ� ��ȯ
	return nd;
}

//��忡 ������ ����
void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

//��忡 ����� ������ ��ȯ
BTData GetData(BTreeNode* bt) {
	return bt->data;
}

//���� Ʈ���� ���� ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

//���� Ʈ���� ������ ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

//���� ���� Ʈ�� ����
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)	 //main���� ���޵� ����� ���ʿ� �̹� ����� ��尡 �ִٸ� ���� ��
		free(main->left);

	main->left = sub;	 	 //���ʿ� sub ��� ����
}

//������ ���� Ʈ�� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL) //main���� ���޵� ����� �����ʿ� �̹� ����� ��尡 �ִٸ� ���� ��
		free(main->right);

	main->right = sub;		 //�����ʿ� sub ��� ����
}

///��ȸ ���� �Լ� ���� �߰�///
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	action(bt->data);	//����� �湮
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);	//����� �湮
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);	//����� �湮
}

///���� Ž�� Ʈ�� ���� ���� �߰�///
//���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּҰ� ��ȯ
BTreeNode* RemoveLeftSubTree(BTreeNode* bt) {
	BTreeNode* delNode;

	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

//������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּҰ� ��ȯ
BTreeNode* RemoveRightSubTree(BTreeNode* bt) {
	BTreeNode* delNode;

	if (bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

//Make...SubTree()�Լ����� ����: ���� �ڽ� ����� �޸� �Ҹ� ���� ���� �ܼ� ��ü
//�޸� �Ҹ��� �������� �ʰ�, main�� ���� �ڽ� ��带 ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	main->left = sub;
}

//�޸� �Ҹ��� �������� �ʰ�, main�� ������ �ڽ� ��带 ����
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	main->right = sub;
}