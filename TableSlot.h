#ifndef __TABLE_SLOT_H__
#define __TABLE_SLOT_H__

#include "TableData.h"	//
//슬롯: 테이블의 각 데이터를 저장할 수 있는 공간 마련

typedef int Key;			//키
typedef Person* Value;		//구조체 변수의 주소값

/* 키 충돌 관련 해결을 위한 체이닝 방법 구현함에 따라 삭제;
enum SlotStatus {EMPTY, DELETED, INUSE};	//열거형 정의 활용하여 슬롯 상태 정의하기
				//저장된 적 없음, 저장되었다 비워짐, 유효한 데이터 저장됨				  */

typedef struct slot {
	Key key;
	Value val;
	/* enum SlotStatus status;		//열거형 선언을 통해 슬롯의 상태를 나타내는 멤버 포함 */
} Slot;
#endif