#ifndef __TABLE_SLOT_H__
#define __TABLE_SLOT_H__

#include "TableData.h"	//
//����: ���̺��� �� �����͸� ������ �� �ִ� ���� ����

typedef int Key;			//Ű
typedef Person* Value;		//����ü ������ �ּҰ�

/* Ű �浹 ���� �ذ��� ���� ü�̴� ��� �����Կ� ���� ����;
enum SlotStatus {EMPTY, DELETED, INUSE};	//������ ���� Ȱ���Ͽ� ���� ���� �����ϱ�
				//����� �� ����, ����Ǿ��� �����, ��ȿ�� ������ �����				  */

typedef struct slot {
	Key key;
	Value val;
	/* enum SlotStatus status;		//������ ������ ���� ������ ���¸� ��Ÿ���� ��� ���� */
} Slot;
#endif