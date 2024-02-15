#include <stdio.h>
#include "BT.h"		//
#include "BSTAVL.h"	//
#include "SearchAVL.h"	///

//���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

//����: ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;	//�θ� ���
	BTreeNode* cNode = *pRoot;	//���� ���
	BTreeNode* nNode = NULL;	//�� ���

	//�� �����Ͱ� ��� ���ο� ��尡 �߰��� ��ġ�� ã��
	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;	//������ Ű�� �ߺ��� ������� ����

		pNode = cNode;

		if (GetData(cNode) > data)	//������ ���� ũ�⿡ ���� �� ����� ���� ��ġ�� ã��
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}	//�ش� ��ġ�� ��带 �����ϱ� ���ؼ�, �̸� �ڽ����� �ϴ� �θ� ����� �ּҰ��� �ʿ��ϹǷ�,

	//pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode();	//�� ����� ����
	SetData(nNode, data);		//�� ��忡 ������ ����

	//pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL) {	//�� ��尡 ��Ʈ ��尡 �ƴ϶��,
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else {					//�� ��尡 ��Ʈ �����,
		*pRoot = nNode;
	}

	///AVL: ���뷱�� ����� �߰��Ͽ� Ȯ��(��� �߰� ��)///
	*pRoot = Rebalance(pRoot);
}

//Ž��: ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst;	//�� ���
	BSTData cd;				//�� ������

	while (cNode != NULL) {
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)				//�� ��󺸴� Ÿ�� ���� ������ ���� �ڽ� ����,
			cNode = GetLeftSubTree(cNode);
		else								//...ũ�� ������ �ڽ� ���� �̵��ϱ�
			cNode = GetRightSubTree(cNode);
	}

	return NULL;	//Ž�� ����� ����Ǿ� ���� ���� ���
}

///����///
//Ʈ������ ��带 �����ϰ�, ���ŵ� ����� �ּҰ� ��ȯ
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	//������ ����� ��Ʈ ����� ��츦 ������ ���
	BTreeNode* pVRoot = MakeBTreeNode();	//���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;		//�θ� ���
	BTreeNode* cNode = *pRoot;		//�ڽ� ���
	BTreeNode* dNode;				//������ ���

	//��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�
	ChangeRightSubTree(pVRoot, *pRoot);

	//���� ����� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;	//pNode�� ���� ����� �θ� ��带 ����Ű�� ����

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);

		if (cNode == NULL)	//���� ����� �������� �ʴ� ���
			return NULL;

		dNode = cNode;		//���� ����� dNode�� ����Ű�� �Ѵ�

		//ù ��° ���: ���� ����� �ܸ� ����� ���
		if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
			if (GetLeftSubTree(pNode) == dNode)	//������ ��尡 ���� �ڽ� �����
				RemoveLeftSubTree(pNode);		//���� �ڽ� ��� Ʈ������ ����
			else								//������ ����
				RemoveRightSubTree(pNode);		//��������
		}

		//�� ��° ���: ���� ����� �ϳ��� �ڽ� ��带 ���� ���
		else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
			BTreeNode* dcNode;	//���� ����� �ڽ� ��� ����Ű�� ����

			//���� ����� �ڽ� ��带 ã��
			if (GetLeftSubTree(dNode) != NULL)		//�ڽ� ��尡 ���ʿ� �ִ� ���
				dcNode = GetLeftSubTree(dNode);
			else									//�ڽ� ��尡 �����ʿ� �ִ� ���
				dcNode = GetRightSubTree(dNode);

			//���� ����� �θ� ���� �ڽ� ��带 ����
			if (GetLeftSubTree(pNode) == dNode)		//���� ����� ���� �ڽ� �����
				ChangeLeftSubTree(pNode, dcNode);		//�������� ����
			else									//���� ����� ������ �ڽ� �����
				ChangeRightSubTree(pNode, dcNode);		//���������� ����
		}

		//�� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
		else {
			BTreeNode* mNode = GetRightSubTree(dNode);	//��ü ��� ����Ŵ(������ ���� Ʈ������ ���� ���� ��**�� ������ ���� ������*)
			BTreeNode* mpNode = dNode;					//��ü ����� �θ� ��� ����Ŵ

			int delData;

			//���� ����� ��ü ��� ã��
			while (GetLeftSubTree(mNode) != NULL) {	//�ڽ� ��尡 NULL�̸� �ߴ�
				mpNode = mNode;					//���� ���� ��**�� ã�� ���� ���� �ڽ� ���� ��� �̵�
				mNode = GetLeftSubTree(mNode);
			}

			//��ü ��忡 ����� ���� ������ ��忡 �����ϱ�
			delData = GetData(dNode);				//���� �� ������ ���
			SetData(dNode, GetData(mNode));			//�����ϱ�

			//��ü ����� �θ� ���� �ڽ� ��带 ���� �����ϱ�
			if (GetLeftSubTree(mpNode) == mNode)				//��ü�� ��尡 ���� �ڽ� ����
				ChangeLeftSubTree(mpNode, GetRIghtSubTree(mNode));	//��ü�� ����� �ڽ� ���*�� �θ� ����� ���ʿ� ����
			else												//��ü�� ��尡 ������ �ڽ� ����
				ChangeRightSubTree(mpNode, GetRightSubTree(mNode));	//��ü�� ����� �ڽ� ���*�� �θ� ����� �����ʿ� ����

			dNode = mNode;
			SetData(dNode, delData);	//��� ������ ����
		}

		//������ ��尡 ��Ʈ ����� ��쿡 ���� �߰��� ó��
		if (GetRightSubTree(pVRoot) != *pRoot)
			*pRoot = GetRightSubTree(pVRoot);		//��Ʈ ����� ������ �ݿ�

		free(pVRoot);	//���� ��Ʈ ����� �Ҹ�

		///AVL: ���뷱�� ����� �߰��Ͽ� Ȯ��(��� ���� ��)///
		*pRoot = Rebalance(pRoot);
		return dNode;	//������ ����� ��ȯ
	}
}

//���� Ž�� Ʈ���� ����� ��� ����� �����͸� ���
void ShowIntData(int data) {	//�Ʒ� �Լ��� �׼� ����
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst, ShowIntData);	//���� ��ȸ�� ����
}

