#include <stdio.h>
#include <stdlib.h>
#include "SearchBTree.h"	//

int main(void) {
	BTreeNode* bstRoot;			//��Ʈ ��带 ����Ű�� ������
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);	//���� Ž�� Ʈ���� ���� �� �ʱ�ȭ

	BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7); 

	//���� Ž�� Ʈ�� Ư�� ��� ���� �� ���
	BSTShowAll(bstRoot); printf("\n");	

	//���� Ž�� Ʈ���� ��� ����
	sNode = BSTRomve(&bstRoot, 3);
	free(sNode);

	//���� Ž�� Ʈ�� Ư�� ��� ���� �� ���
	BSTShowAll(bstRoot); printf("\n");

	return 0;
}