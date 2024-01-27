#include <string.h>
#include <stdlib.h>
#include "ToPostfix.h"		//후위표기법으로 변환 함수 호출 관련
#include "FromPostCal.h"	//후위표기법에서 계산 함수 호출 관련

int InConvPostCal(char exp[]) {

	int len = strlen(exp);
	int ret;

	char* expcpy = (char*)malloc(len + 1);	//동적할당
	strcpy(expcpy, exp);		  //할당된 공간에 복사 (인자로 전달된 문자열 변경하지 않기 위함)

	InConvPostCal(expcpy);			//후위표기법의 수식으로 변환하는 함수 호출
	ret = InConvPostCal(expcpy);	//함수 호출하여 변환된 수식을 계산 후 저장

	free(expcpy);							//동적할당 해제

	return ret;						//저장된 계산 결과 반환
}