#include <stdio.h>
#include "BT.h"		//
#include "BSTAVL.h"	//

int main(void) {

	BTreeNode* avlRoot;
	BTreeNode* clNode;	//���� ���� ���
	BTreeNode* crNode;	//���� ������ ���

	BSTMakeAndInit(&avlRoot);	//���� Ž�� AVL Ʈ��

	BSTInsert(&avlRoot, 1); BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3); BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5); BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7); BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	//RRȸ���� ��� 
	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));
	
	return 0;
}