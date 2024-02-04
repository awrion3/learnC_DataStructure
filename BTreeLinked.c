#include <stdio.h>
#include <stdlib.h>
#include "BTreeLinked.h"	//
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

//다만 연결을 위한 해제에 있어, 기존에 연결된 노드가 하나 이상이라면
//해당 기존 연결 노드 해제 시, 그에 종속된 노드들이 남아 메모리 누수 문제 발생
//하위 노드들을 모두 방문하여 삭제하기 위한 순회는 아직 구현 안함