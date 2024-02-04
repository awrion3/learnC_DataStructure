#ifndef __B_TREE_EXP_H__
#define __B_TREE_EXP_H__

#include "BTreeT.h"	//

//�Լ� ���� ����//
//���� Ʈ�� ����(���� ǥ��� ������ �Է¹޾� ���� Ʈ�� ���� ��, ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ)
BTreeNode* MakeExpTree(char exp[]);
//���� Ʈ�� ���
int EvalExpTree(BTreeNode* bt);

//���� Ʈ�� ��� ���:
//���� ǥ��� ��� ���(���� ��ȸ ����)
void ShowPrefixTypeExp(BTreeNode* bt);
//���� ǥ��� ��� ���(���� ��ȸ ����)
void ShowInfixTypeExp(BTreeNode* bt);
//���� ǥ��� ��� ���(���� ��ȸ ����)
void ShowPostfixTypeExp(BTreeNode* bt);

#endif