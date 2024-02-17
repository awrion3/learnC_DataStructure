#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TableData.h"	//

//키 추출
int GetSSN(Person* p) {
	return p->ssn;
}

//출력
void ShowPerInfo(Person* p) {
	printf("주민등록번호: %d\n", p->ssn);
	printf("이름: %s\n", p->name);
	printf("주소: %s\n", p->addr);
}

//구조채 생성 및 초기화
Person* MakePersonData(int ssn, char* name, char* addr) {
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}