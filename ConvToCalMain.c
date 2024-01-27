#include <stdio.h>
#include "ConvToCal.h"	//

int main(void) {

	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	//후위표기법으로 변환하고 이를 계산하는 두 함수를 호출하는 함수 사용
	printf("%s = %d \n", exp1, InConvPostCal(exp1));
	printf("%s = %d \n", exp2, InConvPostCal(exp2));
	printf("%s = %d \n", exp3, InConvPostCal(exp3));

	return 0;
}