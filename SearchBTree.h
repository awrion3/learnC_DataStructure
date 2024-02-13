#ifndef __SEARCH_B_TREE_H__
#define __SEARCH_B_TREE_H__

#include "SearchBT.h"	//

typedef BTData BSTData;

//���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

//����: ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data);

//Ž��: ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

///����///
//Ʈ������ ��带 �����ϰ�, ���ŵ� ����� �ּҰ� ��ȯ
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

//���� Ž�� Ʈ���� ����� ��� ����� �����͸� ���
void BSTShowAll(BTreeNode* bst);

#endif