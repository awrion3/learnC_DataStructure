#include <stdio.h>
#include "BT.h"		//
#include "BSTAVL.h"	//

int main(void) {

	BTreeNode* avlRoot;
	BTreeNode* clNode;	//현재 왼쪽 노드
	BTreeNode* crNode;	//현재 오른쪽 노드

	BSTMakeAndInit(&avlRoot);	//이진 탐색 AVL 트리

	BSTInsert(&avlRoot, 1); BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3); BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5); BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7); BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	//RR회전의 결과 
	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
	
	return 0;
}