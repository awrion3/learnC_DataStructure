#ifndef __TABLE_DATA_H__
#define __TABLE_DATA_H__

#define STR_LEN 50

//테이블에 저장된 값//
typedef struct person {	
	int ssn;				//주민등록번호(키)
	char name[STR_LEN];		//이름
	char addr[STR_LEN];		//주소
} Person;

int GetSSN(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);
#endif