#include <stdio.h>
#include "SearchBTree.h"	//

int main(void) {

	BTreeNode* bstRoot;	//이진 탐색 트리의 루트 노드 포인터
	BTreeNode* sNode;	//노드 찾기

	BSTMakeAndInit(&bstRoot);	//이진 탐색 트리의 생성 및 초기화

	//데이터 저장
	BSTInsert(&bstRoot, 9); BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8); BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	//데이터 탐색 및 결과 출력
	sNode = BSTSearch(bstRoot, 1);
	
	if (sNode == NULL)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));
	
	///데이터 삭제는 미구현///
	return 0;
}