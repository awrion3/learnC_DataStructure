#include <stdio.h>
#include "BT.h"		//
#include "BSTAVL.h"	//
#include "SearchAVL.h"	///

//이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

//삽입: 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;	//부모 노드
	BTreeNode* cNode = *pRoot;	//현재 노드
	BTreeNode* nNode = NULL;	//새 노드

	//새 데이터가 담긴 새로운 노드가 추가될 위치를 찾기
	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;	//데이터 키의 중복을 허용하지 않음

		pNode = cNode;

		if (GetData(cNode) > data)	//저장할 값의 크기에 따라 새 노드의 저장 위치를 찾기
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}	//해당 위치에 노드를 저장하기 위해선, 이를 자식으로 하는 부모 노드의 주소값이 필요하므로,

	//pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode();	//새 노드의 생성
	SetData(nNode, data);		//새 노드에 데이터 저장

	//pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL) {	//새 노드가 루트 노드가 아니라면,
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else {					//새 노드가 루트 노드라면,
		*pRoot = nNode;
	}

	///AVL: 리밸런싱 기능을 추가하여 확장(노드 추가 후)///
	*pRoot = Rebalance(pRoot);
}

//탐색: 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst;	//현 노드
	BSTData cd;				//현 데이터

	while (cNode != NULL) {
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)				//비교 대상보다 타겟 값이 작으면 왼쪽 자식 노드로,
			cNode = GetLeftSubTree(cNode);
		else								//...크면 오른쪽 자식 노드로 이동하기
			cNode = GetRightSubTree(cNode);
	}

	return NULL;	//탐색 대상이 저장되어 있지 않은 경우
}

///삭제///
//트리에서 노드를 제거하고, 제거된 노드의 주소값 반환
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	//삭제된 대상이 루트 노드인 경우를 별도로 고려
	BTreeNode* pVRoot = MakeBTreeNode();	//가상 루트 노드
	BTreeNode* pNode = pVRoot;		//부모 노드
	BTreeNode* cNode = *pRoot;		//자식 노드
	BTreeNode* dNode;				//삭제할 노드

	//루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다
	ChangeRightSubTree(pVRoot, *pRoot);

	//삭제 대상인 노드를 탐색
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;	//pNode가 삭제 대상의 부모 노드를 가리키기 위함

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);

		if (cNode == NULL)	//삭제 대상이 존재하지 않는 경우
			return NULL;

		dNode = cNode;		//삭제 대상을 dNode가 가리키게 한다

		//첫 번째 경우: 삭제 대상이 단말 노드인 경우
		if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
			if (GetLeftSubTree(pNode) == dNode)	//삭제할 노드가 왼쪽 자식 노드라면
				RemoveLeftSubTree(pNode);		//왼쪽 자식 노드 트리에서 제거
			else								//오른쪽 관련
				RemoveRightSubTree(pNode);		//마찬가지
		}

		//두 번째 경우: 삭제 대상이 하나의 자식 노드를 갖는 경우
		else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
			BTreeNode* dcNode;	//삭제 대상의 자식 노드 가리키기 위함

			//삭제 대상의 자식 노드를 찾기
			if (GetLeftSubTree(dNode) != NULL)		//자식 노드가 왼쪽에 있는 경우
				dcNode = GetLeftSubTree(dNode);
			else									//자식 노드가 오른쪽에 있는 경우
				dcNode = GetRightSubTree(dNode);

			//삭제 대상의 부모 노드와 자식 노드를 연결
			if (GetLeftSubTree(pNode) == dNode)		//삭제 대상이 왼쪽 자식 노드라면
				ChangeLeftSubTree(pNode, dcNode);		//왼쪽으로 연결
			else									//삭제 대상이 오른쪽 자식 노드라면
				ChangeRightSubTree(pNode, dcNode);		//오른쪽으로 연결
		}

		//세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
		else {
			BTreeNode* mNode = GetRightSubTree(dNode);	//대체 노드 가리킴(오른쪽 서브 트리에서 가장 작은 값**을 저장한 노드로 설정시*)
			BTreeNode* mpNode = dNode;					//대체 노드의 부모 노드 가리킴

			int delData;

			//삭제 대상의 대체 노드 찾기
			while (GetLeftSubTree(mNode) != NULL) {	//자식 노드가 NULL이면 중단
				mpNode = mNode;					//가장 작은 값**을 찾기 위해 왼쪽 자식 노드로 계속 이동
				mNode = GetLeftSubTree(mNode);
			}

			//대체 노드에 저장된 값을 삭제할 노드에 대입하기
			delData = GetData(dNode);				//대입 전 데이터 백업
			SetData(dNode, GetData(mNode));			//대입하기

			//대체 노드의 부모 노드와 자식 노드를 연결 갱신하기
			if (GetLeftSubTree(mpNode) == mNode)				//대체할 노드가 왼쪽 자식 노드면
				ChangeLeftSubTree(mpNode, GetRIghtSubTree(mNode));	//대체할 노드의 자식 노드*를 부모 노드의 왼쪽에 연결
			else												//대체할 노드가 오른쪽 자식 노드면
				ChangeRightSubTree(mpNode, GetRightSubTree(mNode));	//대체할 노드의 자식 노드*를 부모 노드의 오른쪽에 연결

			dNode = mNode;
			SetData(dNode, delData);	//백업 데이터 복원
		}

		//삭제된 노드가 루트 노드인 경우에 대한 추가적 처리
		if (GetRightSubTree(pVRoot) != *pRoot)
			*pRoot = GetRightSubTree(pVRoot);		//루트 노드의 변경을 반영

		free(pVRoot);	//가상 루트 노드의 소멸

		///AVL: 리밸런싱 기능을 추가하여 확장(노드 삭제 후)///
		*pRoot = Rebalance(pRoot);
		return dNode;	//삭제된 대상의 반환
	}
}

//이진 탐색 트리에 저장된 모든 노드의 데이터를 출력
void ShowIntData(int data) {	//아래 함수의 액션 인자
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst, ShowIntData);	//중위 순회로 설정
}

