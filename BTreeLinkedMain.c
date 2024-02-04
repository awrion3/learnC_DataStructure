#include <stdio.h>
#include "BTreeLinked.h"	//

int main(void) {

	//노드 생성 및 초기화
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	//노드에 데이터 저장
	SetData(bt1, 1); 
	SetData(bt2, 2); SetData(bt3, 3); 
	SetData(bt4, 4);

	//서브 트리 연결
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	//데이터 출력
	//루트 노드bt1의 왼쪽 서브 트리의 루트 노드bt2 데이터 출력
	printf("%d\n", GetData(GetLeftSubTree(bt1)));	
	//루트 노드bt1의 왼쪽 서브 트리의 루트 노드bt2의 .... bt4 데이터 출력
	printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}