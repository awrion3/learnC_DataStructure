#include <stdio.h>
#include <stdlib.h>
#include "Table.h"		//
#include "LinkedL.h"	////

void TableInit(Table* pt, HashFunc* f) {

	//��� ���� �ʱ�ȭ
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));
		/*(pt->tbl[i]).status = EMPTY;*/

	pt->hf = f;	//�ؽ� �Լ� ���
}

void TBLInsert(Table* pt, Key k, Value v) {
	int hv = pt->hf(k);	
	Slot ns = { k, v };	/* */

	if (TBLSearch(pt, k) != NULL) {			//�����Ϸ��µ� Ű �ߺ� �߻��ߴٸ�
		printf("Ű �ߺ� ���� �߻� \n");
		return;
	}
	else
		LInsert(&(pt->tbl[hv]), ns);
	/*
	pt->tbl[hv].val = v;	//Ű�� �������� �����Ͽ� ������ �ʱ�ȭ
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
	*/
}

Value TBLDelete(Table* pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;	/* */

	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k) {
			LRemove(&(pt->tbl[hv]));

			return cSlot.val;	//������ �� ��ȯ
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {	//�ι�° ���ĺ���
				if (cSlot.key == k) {
					LRemove(&(pt->tbl[hv]));

					return cSlot.val;	//������ �� ��ȯ
				}
			}
		}
	}

	return NULL;	//������ �� ���� ���
	/*
	if ((pt->tbl[hv]).status != INUSE)	//����� ���� ���� ��� NULL ��ȯ
		return NULL;
	else {
		(pt->tbl[hv]).status = DELETED;

		return (pt->tbl[hv]).val;		//�Ҹ� ����� �� ��ȯ
	}
	*/
}

Value TBLSearch(Table* pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;	/* */

	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k) {
			return cSlot.val;			//Ž���� �� ��ȯ
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {	//�ι�° ���ĺ���
				if (cSlot.key == k) {
					return cSlot.val;	//Ž���� �� ��ȯ
				}
			}
		}
	}

	return NULL;	//Ž���� �� ���� ���
	/*
	if ((pt->tbl[hv]).status != INUSE)	//����� ���� ���� ��� NULL ��ȯ
		return NULL;
	else 
		return (pt->tbl[hv]).val;		//Ž�� ����� �� ��ȯ
	*/
}