#include <stdio.h>
#include <stdlib.h>
#include "TableData.h"	//
#include "Table.h"		//

int MyHashFunc(int k) {	//�ؽ� �Լ� ����
	return k % 100;
}

int main(void) {

	Table myTbl;
	Person *np, *sp, *rp;

	TBLInit(&myTbl, MyHashFunc);	//���̺� ���� �� �ʱ�ȭ

	//������ �Է�
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	
	np = MakePersonData(20120012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	
	np = MakePersonData(20120049, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	//������ Ž��
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL)			//Ű�� ���� �ش� �����Ͱ� �����ϸ� ���
		ShowPerInfo(sp);

	//������ ����
	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL)			//Ű�� ���� �ش� �����Ͱ� �����ϸ� �Ҵ� ����
		free(rp);

	return 0;
}