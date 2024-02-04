#include <stdio.h>
#include "BTreeLinked.h"	//

//중위 순회(왼 서브->루트->오 서브)를 통한 이진 트리 접근
void InorderTraverse(BTreeNode* bt) {
	if (bt == NULL)			//노드가 공집합이면 순회 종료
		return;

	InorderTraverse(bt->left);	//왼쪽 서브 트리의 순회
	printf("%d \n", bt->data);	//루트 노드 방문
	InorderTraverse(bt->right);	//오른쪽 서브 트리의 순회
	//Preorder전위 Postorder후위 순회는 이 셋의 순서만 차이
}

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

	//전체 데이터 출력//
	InorderTraverse(bt1);

	return 0;
}