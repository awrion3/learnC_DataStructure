#ifndef __B_S_T_A_V_L_H__
#define __B_S_T_A_V_L_H__

#include "BT.h"	//

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

///���� �� ���� �Լ� ���� AVL ��� �߰�: ���뷱�� ����� ���Ͽ� Ȯ��///
#endif