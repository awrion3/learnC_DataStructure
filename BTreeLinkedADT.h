/*
(연결 리스트 기반) 이진 트리 자료구조의 추상 자료형(ADT) 기능 Operations:

BTreeNode* MakeBTreeNode(void);				//노드 생성 및 초기화

void SetData(BTreeNode* bt, BTData data);	//노드에 데이터 저장
BTData GetData(BTreeNode* bt);				//노드에 저장된 데이터 반환

BTreeNode* GetLeftSubTree(BTreeNode* bt);	//이진 트리의 왼쪽 서브 트리의 루트 노드 주소값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);	//이진 트리의 오른쪽 서브 트리의 루트 노드 주소값 반환

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);	//왼쪽 서브 트리 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	//오른쪽 서브 트리 연결
*/