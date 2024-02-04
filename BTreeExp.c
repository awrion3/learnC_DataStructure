#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //
#include <ctype.h>
#include "StackBT.h" //
#include "BTreeT.h" 

//���� Ʈ�� ����:
//���� ǥ��� ������ �Է¹޾� ���� Ʈ�� ���� ��, ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ
BTreeNode* MakeExpTree(char exp[]) {
	Stack stack;		//���� ����
	BTreeNode* pnode;	//��Ʈ ��� ����
	int expLen = strlen(exp);	//���� ǥ��� ��� ���ڿ� ���� ���ϱ�
	StackInit(&stack);	//���� �ʱ�ȭ

	for (int i = 0; i < expLen; i++) {
		pnode = MakeBTreeNode();	//��� ���� �� ���� �ʱ�ȭ

		if (isdigit(exp[i])) {		//�ǿ����ڸ�
			SetData(pnode, exp[i] - '0');	//�ش� �ǿ����� ���ڸ� ������ �ٲپ� ��忡 ����
		}
		else {						//�����ڸ�
			MakeRightSubTree(pnode, SPop(&stack));	//������ ���� ������ ���� Ʈ���� �����ʿ� ����
			MakeLeftSubTree(pnode, SPop(&stack));	//������ �Ʒ� ������ ���� Ʈ���� ���ʿ� ����
			SetData(pnode, exp[i]);			//�ش� ������ ���ڸ� ��忡 ����
		}

		SPush(&stack, pnode);		//���� ���� Ʈ�� Ȥ�� ��带 ���ÿ� �ױ�
	}

	return SPop(&stack);			//���� ���� Ʈ���� ���ÿ��� ������
}

//���� Ʈ�� ���:
int EvalExpTree(BTreeNode* bt) {
	int op1, op2;
	
	//��� Ż�� ����
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);		//�ܸ� �����, �ش� �ǿ����� ������ ��ȯ

	//��������� ���� (�ܸ� ��尡 �ƴ� ���� Ʈ�����, �ش� ���� Ʈ���� ��Ʈ ��� �������� �Ͽ�)
	op1 = EvalExpTree(GetData(GetLeftSubTree(bt)));		//ù��° �ǿ�����(����) 
	op2 = EvalExpTree(GetData(GetRightSubTree(bt)));	//�ι�° �ǿ�����(������)

	switch (GetData(bt)) {		//�����ڿ� ���� ��� ��� ��ȯ
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}

	return 0;	//�⺻�� 0 ��ȯ
}

//���� Ʈ�� ��� ���:
void ShowNodeData(int data) {		//��� ��� ���� �Լ�
	if (0 <= data && data <= 9)	//������ ���
		printf("%d ", data);
	else						//����(������)�� ���
		printf("%c ", data);
}

//���� ǥ��� ��� ���(���� ��ȸ ����)
void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);	//�ι�° ���ڷ� action�Լ� ���
}

//���� ǥ��� ��� ���(���� ��ȸ ����)
void ShowInfixTypeExp(BTreeNode* bt) {
	InorderTraverse(bt, ShowNodeData);
}

//���� ǥ��� ��� ���(���� ��ȸ ����)
void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}