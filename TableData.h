#ifndef __TABLE_DATA_H__
#define __TABLE_DATA_H__

#define STR_LEN 50

//���̺� ����� ��//
typedef struct person {	
	int ssn;				//�ֹε�Ϲ�ȣ(Ű)
	char name[STR_LEN];		//�̸�
	char addr[STR_LEN];		//�ּ�
} Person;

int GetSSN(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);
#endif