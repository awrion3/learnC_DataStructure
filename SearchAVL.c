#include <stdio.h>
#include "BT.h"	//
//AVL: 리밸런싱 관련 함수들 정의//

//LL회전
BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode;	//부모 노드
	BTreeNode* cNode;	//자식 노드

	//부모 노드와 자식 노드가 LL회전을 위해 적절한 위치를 가리키게 함
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	//실제 LL회전
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));	//서브 트리 이동
	ChangeRightSubTree(cNode, pNode);

	//LL회전으로 인해서 변경된 루트 노드의 주소값 반환
	return cNode;
}

//RR회전
BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;	//부모 노드
	BTreeNode* cNode;	//자식 노드

	//부모 노드와 자식 노드가 RR회전을 위해 적절한 위치를 가리키게 함
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	//실제 RR회전
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));	//서브 트리 이동
	ChangeLeftSubTree(cNode, pNode);

	//RR회전으로 인해서 변경된 루트 노드의 주소값 반환
	return cNode;
}

//LR회전: 부분 RR회전 + LL회전
BTreeNode* RotateLR(BTreeNode* bst) {
	BTreeNode* pNode;	//부모 노드
	BTreeNode* cNode;	//자식 노드

	//부모 노드와 자식 노드가 LR회전을 위해 적절한 위치를 가리키게 함
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	//실제 LR회전
	ChangeLeftSubTree(pNode, RotateRR(cNode));	//부분 RR회전
	return RotateLL(pNode);						//LL회전
}

//RL회전: 부분 LL회전 + RR회전
BTreeNode* RotateRL(BTreeNode* bst) {
	BTreeNode* pNode;	//부모 노드
	BTreeNode* cNode;	//자식 노드

	//부모 노드와 자식 노드가 RL회전을 위해 적절한 위치를 가리키게 함
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	//실제 RL회전
	ChangeRightSubTree(pNode, RotateLL(cNode));	//부분 LL회전
	return RotateRR(pNode);						//RR회전
}

//트리의 높이를 계산하여 반환
int GetHeight(BTreeNode* bst) {
	int leftH, rightH;			//불균형 여부를 확인하기 위함

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));		//왼쪽 서브 트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));	//오른쪽 서브 트리 높이 계산

	//큰 값의 높이를 반환
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

//두 서브 트리의 높이의 차(균형 인수)를 반환
int GetHeightDiff(BTreeNode* bst) {
	int lsh, rsh;	//왼쪽 및 오른쪽 서브 트리 높이

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));	//왼쪽 서브 트리 높이 계산
	rsh = GetHeight(GetRightSubTree(bst));	//오른쪽 서브 트리 높이 계산

	return lsh - rsh;	//균형 인수 계산 결과 반환
}

//트리의 균형 잡기//
BTreeNode* Rebalance(BTreeNode** pRoot) {
	int hDiff = GetHeightDiff(*pRoot);	//균형 인수 계산

	//균형 인수가 +2 이상이면 LL상태 또는 LR상태임
	if (hDiff > 1) {	//왼쪽 서브 트리 방향으로 높이가 2이상인 경우
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)	//서브 트리에서 양수값 만난 경우
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	//균형 인수가 -2 이하이면 RR상태 또는 RL상태임
	if (hDiff < -1) {	//오른쪽 서브 트리 방향으로 높이가 2이상인 경우
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)	//서브 트리에서 음수값 만난 경우
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;	//루트 노드 반환
}