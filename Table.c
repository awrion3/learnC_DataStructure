#include <stdio.h>
#include <stdlib.h>
#include "Table.h"		//
#include "LinkedL.h"	////

void TableInit(Table* pt, HashFunc* f) {

	//모든 슬롯 초기화
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));
		/*(pt->tbl[i]).status = EMPTY;*/

	pt->hf = f;	//해쉬 함수 등록
}

void TBLInsert(Table* pt, Key k, Value v) {
	int hv = pt->hf(k);	
	Slot ns = { k, v };	/* */

	if (TBLSearch(pt, k) != NULL) {			//삽입하려는데 키 중복 발생했다면
		printf("키 중복 오류 발생 \n");
		return;
	}
	else
		LInsert(&(pt->tbl[hv]), ns);
	/*
	pt->tbl[hv].val = v;	//키를 바탕으로 접근하여 데이터 초기화
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

			return cSlot.val;	//삭제한 값 반환
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {	//두번째 이후부터
				if (cSlot.key == k) {
					LRemove(&(pt->tbl[hv]));

					return cSlot.val;	//삭제한 값 반환
				}
			}
		}
	}

	return NULL;	//삭제할 게 없는 경우
	/*
	if ((pt->tbl[hv]).status != INUSE)	//저장된 값이 없는 경우 NULL 반환
		return NULL;
	else {
		(pt->tbl[hv]).status = DELETED;

		return (pt->tbl[hv]).val;		//소멸 대상의 값 반환
	}
	*/
}

Value TBLSearch(Table* pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;	/* */

	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k) {
			return cSlot.val;			//탐색한 값 반환
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {	//두번째 이후부터
				if (cSlot.key == k) {
					return cSlot.val;	//탐색한 값 반환
				}
			}
		}
	}

	return NULL;	//탐색할 게 없는 경우
	/*
	if ((pt->tbl[hv]).status != INUSE)	//저장된 값이 없는 경우 NULL 반환
		return NULL;
	else 
		return (pt->tbl[hv]).val;		//탐색 대상의 값 반환
	*/
}