#include <stdio.h>
#include "BT.h"	//
//AVL: ���뷱�� ���� �Լ��� ����//

//LLȸ��
BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode;	//�θ� ���
	BTreeNode* cNode;	//�ڽ� ���

	//�θ� ���� �ڽ� ��尡 LLȸ���� ���� ������ ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	//���� LLȸ��
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));	//���� Ʈ�� �̵�
	ChangeRightSubTree(cNode, pNode);

	//LLȸ������ ���ؼ� ����� ��Ʈ ����� �ּҰ� ��ȯ
	return cNode;
}

//RRȸ��
BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;	//�θ� ���
	BTreeNode* cNode;	//�ڽ� ���

	//�θ� ���� �ڽ� ��尡 RRȸ���� ���� ������ ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	//���� RRȸ��
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));	//���� Ʈ�� �̵�
	ChangeLeftSubTree(cNode, pNode);

	//RRȸ������ ���ؼ� ����� ��Ʈ ����� �ּҰ� ��ȯ
	return cNode;
}

//LRȸ��: �κ� RRȸ�� + LLȸ��
BTreeNode* RotateLR(BTreeNode* bst) {
	BTreeNode* pNode;	//�θ� ���
	BTreeNode* cNode;	//�ڽ� ���

	//�θ� ���� �ڽ� ��尡 LRȸ���� ���� ������ ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	//���� LRȸ��
	ChangeLeftSubTree(pNode, RotateRR(cNode));	//�κ� RRȸ��
	return RotateLL(pNode);						//LLȸ��
}

//RLȸ��: �κ� LLȸ�� + RRȸ��
BTreeNode* RotateRL(BTreeNode* bst) {
	BTreeNode* pNode;	//�θ� ���
	BTreeNode* cNode;	//�ڽ� ���

	//�θ� ���� �ڽ� ��尡 RLȸ���� ���� ������ ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	//���� RLȸ��
	ChangeRightSubTree(pNode, RotateLL(cNode));	//�κ� LLȸ��
	return RotateRR(pNode);						//RRȸ��
}

//Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode* bst) {
	int leftH, rightH;			//�ұ��� ���θ� Ȯ���ϱ� ����

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));		//���� ���� Ʈ�� ���� ���
	rightH = GetHeight(GetRightSubTree(bst));	//������ ���� Ʈ�� ���� ���

	//ū ���� ���̸� ��ȯ
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

//�� ���� Ʈ���� ������ ��(���� �μ�)�� ��ȯ
int GetHeightDiff(BTreeNode* bst) {
	int lsh, rsh;	//���� �� ������ ���� Ʈ�� ����

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));	//���� ���� Ʈ�� ���� ���
	rsh = GetHeight(GetRightSubTree(bst));	//������ ���� Ʈ�� ���� ���

	return lsh - rsh;	//���� �μ� ��� ��� ��ȯ
}

//Ʈ���� ���� ���//
BTreeNode* Rebalance(BTreeNode** pRoot) {
	int hDiff = GetHeightDiff(*pRoot);	//���� �μ� ���

	//���� �μ��� +2 �̻��̸� LL���� �Ǵ� LR������
	if (hDiff > 1) {	//���� ���� Ʈ�� �������� ���̰� 2�̻��� ���
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)	//���� Ʈ������ ����� ���� ���
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	//���� �μ��� -2 �����̸� RR���� �Ǵ� RL������
	if (hDiff < -1) {	//������ ���� Ʈ�� �������� ���̰� 2�̻��� ���
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)	//���� Ʈ������ ������ ���� ���
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;	//��Ʈ ��� ��ȯ
}