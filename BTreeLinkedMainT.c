#include <stdio.h>
#include "BTreeLinkedT.h"	//

//함수 원형 선언
void ShowIntData(int data);	//노드 방문해서 할 동작 결정

int main(void) {

	//노드 생성 및 초기화
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	//노드에 데이터 저장
	SetData(bt1, 1); SetData(bt2, 2); 
	SetData(bt3, 3); SetData(bt4, 4);
	SetData(bt5, 5); SetData(bt6, 6);

	//서브 트리 연결
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeLeftSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);

	//트리 순회 및 출력
	PreorderTraverse(bt1, ShowIntData);		//전위
	printf("\n");
	InorderTraverse(bt1, ShowIntData);		//중위
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);	//후위 순회
	printf("\n");

	return 0;
}

//함수 정의: 노드 접근하여 출력하는 동작 실행
void ShowIntData(int data) {
	printf("%d ", data);
}