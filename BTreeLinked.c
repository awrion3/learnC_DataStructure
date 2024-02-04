#include <stdio.h>
#include <stdlib.h>
#include "BTreeLinked.h"	//
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

//�ٸ� ������ ���� ������ �־�, ������ ����� ��尡 �ϳ� �̻��̶��
//�ش� ���� ���� ��� ���� ��, �׿� ���ӵ� ������ ���� �޸� ���� ���� �߻�
//���� ������ ��� �湮�Ͽ� �����ϱ� ���� ��ȸ�� ���� ���� ����