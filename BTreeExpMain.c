#include <stdio.h>
#include "BTreeExp.h"	//

int main(void) {

	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);		//���� Ʈ�� ����

	ShowPrefixTypeExp(eTree); printf("\n");		//���� ǥ��� ��� ���� Ʈ�� ���
	ShowInfixTypeExp(eTree); printf("\n");		//����...
	ShowPostfixTypeExp(eTree); printf("\n");	//����...

	printf("���� ���: %d \n", EvalExpTree(eTree));	   //���� Ʈ�� ���� ��� ���

	return 0;
}