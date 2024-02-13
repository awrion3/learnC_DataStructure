#include <stdio.h>
#include "SearchBTree.h"	//

int main(void) {

	BTreeNode* bstRoot;	//���� Ž�� Ʈ���� ��Ʈ ��� ������
	BTreeNode* sNode;	//��� ã��

	BSTMakeAndInit(&bstRoot);	//���� Ž�� Ʈ���� ���� �� �ʱ�ȭ

	//������ ����
	BSTInsert(&bstRoot, 9); BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8); BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	//������ Ž�� �� ��� ���
	sNode = BSTSearch(bstRoot, 1);
	
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));
	
	///������ ������ �̱���///
	return 0;
}