/*
(���� ����Ʈ ���) ���� Ʈ�� �ڷᱸ���� �߻� �ڷ���(ADT) ��� Operations:

BTreeNode* MakeBTreeNode(void);				//��� ���� �� �ʱ�ȭ

void SetData(BTreeNode* bt, BTData data);	//��忡 ������ ����
BTData GetData(BTreeNode* bt);				//��忡 ����� ������ ��ȯ

BTreeNode* GetLeftSubTree(BTreeNode* bt);	//���� Ʈ���� ���� ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt);	//���� Ʈ���� ������ ���� Ʈ���� ��Ʈ ��� �ּҰ� ��ȯ

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);	//���� ���� Ʈ�� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	//������ ���� Ʈ�� ����
*/