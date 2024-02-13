#include <stdio.h>
#include <stdlib.h>
#include "SearchBTree.h"	//

int main(void) {
	BTreeNode* bstRoot;			//루트 노드를 가리키는 포인터
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);	//이진 탐색 트리의 생성 및 초기화

	BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7); 

	//이진 탐색 트리 특정 노드 삭제 전 출력
	BSTShowAll(bstRoot); printf("\n");	

	//이진 탐색 트리의 노드 삭제
	sNode = BSTRomve(&bstRoot, 3);
	free(sNode);

	//이진 탐색 트리 특정 노드 삭제 후 출력
	BSTShowAll(bstRoot); printf("\n");

	return 0;
}