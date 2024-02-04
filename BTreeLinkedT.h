#ifndef __B_TREE_LINKED_T_H__
#define __B_TREE_LINKED_T_H__
//���� ����Ʈ ��� Ʈ�� ����

typedef int BTData;

//���� Ʈ���� ��� ����(���ÿ� ���� Ʈ�� ����)
typedef struct bTreeNode {
	BTData data;
	struct bTreeNode* left;
	struct bTreeNode* right;
} BTreeNode;

//�Լ� ���� ����
BTreeNode* MakeBTreeNode(void);				//��� ���� �� �ʱ�ȭ

void SetData(BTreeNode* bt, BTData data);	//��忡 ������ ����
BTData GetData(BTreeNode* bt);				//��忡 ����� ������ ��ȯ

BTreeNode* GetLeftSubTree(BTreeNode* bt);	//���� Ʈ���� ���� ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt);	//���� Ʈ���� ������ ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);	//���� ���� Ʈ�� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	//������ ���� Ʈ�� ����

//��ȸ ���� �߰�//
//�Լ� �����͸� �ڷ������� ����
typedef void (*VisitFuncPtr) (BTData data);	//��ȯ��void (�Լ��������̸�) (�Լ�����)

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);	//���� ��ȸ
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);	//���� ��ȸ
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);	//���� ��ȸ
//�Լ� �ּҰ��� ���� action�� ���� �޾� ����� �湮 ����
#endif