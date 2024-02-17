#ifndef __TABLE_H__
#define __TABLE_H__

#include "TableSlot.h"	//
#include "LinkedL.h"	//

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);	//Ű ���� �ؽ� �Լ�

typedef struct table {		   //���̺� ���� ����ü
	/*	Slot tbl[MAX_TBL]; */
	List tbl[MAX_TBL];
	HashFunc* hf;
} Table;

//���̺��� �ʱ�ȭ
void TBLInit(Table* pt, HashFunc* f);

//���̺� Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v);

//Ű�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table* pt, Key k);

//Ű�� �ٰŷ� ���̺��� ������ Ž��
Value TBLSearch(Table* pt, Key k);
#endif