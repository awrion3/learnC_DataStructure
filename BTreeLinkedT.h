#ifndef __B_TREE_LINKED_T_H__
#define __B_TREE_LINKED_T_H__
//연결 리스트 기반 트리 구현

typedef int BTData;

//이진 트리의 노드 구현(동시에 이진 트리 구현)
typedef struct bTreeNode {
	BTData data;
	struct bTreeNode* left;
	struct bTreeNode* right;
} BTreeNode;

//함수 원형 선언
BTreeNode* MakeBTreeNode(void);				//노드 생성 및 초기화

void SetData(BTreeNode* bt, BTData data);	//노드에 데이터 저장
BTData GetData(BTreeNode* bt);				//노드에 저장된 데이터 반환

BTreeNode* GetLeftSubTree(BTreeNode* bt);	//이진 트리의 왼쪽 서브 트리의 루트 노드 주소값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);	//이진 트리의 오른쪽 서브 트리의 루트 노드 주소값 반환

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);	//왼쪽 서브 트리 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	//오른쪽 서브 트리 연결

//순회 관련 추가//
//함수 포인터를 자료형으로 정의
typedef void (*VisitFuncPtr) (BTData data);	//반환값void (함수포인터이름) (함수인자)

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);	//전위 순회
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);	//중위 순회
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);	//후위 순회
//함수 주소값을 인자 action을 통해 받아 노드의 방문 결정
#endif