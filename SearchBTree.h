#ifndef __SEARCH_B_TREE_H__
#define __SEARCH_B_TREE_H__

#include "SearchBT.h"	//

typedef BTData BSTData;

//이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot);

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst);

//삽입: 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data);

//탐색: 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

///삭제///
//트리에서 노드를 제거하고, 제거된 노드의 주소값 반환
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

//이진 탐색 트리에 저장된 모든 노드의 데이터를 출력
void BSTShowAll(BTreeNode* bst);

#endif