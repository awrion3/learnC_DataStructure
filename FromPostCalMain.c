#include <stdio.h>
#include "FromPostCal.h"	//

int main(void) {

	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	//후위표기법의 수식을 계산하여 결과 출력
	printf("%s = %d \n", postExp1, PostCal(postExp1));
	printf("%s = %d \n", postExp2, PostCal(postExp2));

	return 0;
}