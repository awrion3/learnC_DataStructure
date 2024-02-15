#include <stdio.h>
#include <stdlib.h>
#include "BT.h"	//BTreeLinkedT.h와 동일
//함수 정의

//노드 생성 및 초기화
BTreeNode* MakeBTreeNode(void) {
	//노드 생성
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	//노드 초기화
	nd->left = NULL;
	nd->right = NULL;
	//노드 주소 반환
	return nd;
}

//노드에 데이터 저장
void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

//노드에 저장된 데이터 반환
BTData GetData(BTreeNode* bt) {
	return bt->data;
}

//이진 트리의 왼쪽 서브 트리의 루트 노드 주소값 반환
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

//이진 트리의 오른쪽 서브 트리의 루트 노드 주소값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

//왼쪽 서브 트리 연결
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)	 //main으로 전달된 노드의 왼쪽에 이미 연결된 노드가 있다면 해제 후
		free(main->left);

	main->left = sub;	 	 //왼쪽에 sub 노드 연결
}

//오른쪽 서브 트리 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL) //main으로 전달된 노드의 오른쪽에 이미 연결된 노드가 있다면 해제 후
		free(main->right);

	main->right = sub;		 //오른쪽에 sub 노드 연결
}

///순회 관련 함수 정의 추가///
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	action(bt->data);	//노드의 방문
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);	//노드의 방문
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);	//노드의 방문
}

///이진 탐색 트리 삭제 관련 추가///
//왼쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소값 반환
BTreeNode* RemoveLeftSubTree(BTreeNode* bt) {
	BTreeNode* delNode;

	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

//오른쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소값 반환
BTreeNode* RemoveRightSubTree(BTreeNode* bt) {
	BTreeNode* delNode;

	if (bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

//Make...SubTree()함수와의 차이: 기존 자식 노드의 메모리 소멸 과정 없는 단순 교체
//메모리 소멸을 수반하지 않고, main의 왼쪽 자식 노드를 변경
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	main->left = sub;
}

//메모리 소멸을 수반하지 않고, main의 오른쪽 자식 노드를 변경
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	main->right = sub;
}