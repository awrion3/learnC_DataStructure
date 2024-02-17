#include <stdio.h>
#include <stdlib.h>
#include "TableData.h"	//
#include "Table.h"		//

int MyHashFunc(int k) {	//해쉬 함수 정의
	return k % 100;
}

int main(void) {

	Table myTbl;
	Person *np, *sp, *rp;

	TBLInit(&myTbl, MyHashFunc);	//테이블 생성 및 초기화

	//데이터 입력
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	
	np = MakePersonData(20120012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	
	np = MakePersonData(20120049, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	//데이터 탐색
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL)			//키에 따른 해당 데이터가 존재하면 출력
		ShowPerInfo(sp);

	//데이터 삭제
	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL)			//키에 따른 해당 데이터가 존재하면 할당 해제
		free(rp);

	return 0;
}