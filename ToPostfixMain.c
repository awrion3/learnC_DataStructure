#include <stdio.h>
#include "ToPostfix.h"	//

int main(void) {

	char exp1[] = "1+1*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	//중위표기법의 수식을 후위표기법으로 변환한 결과 출력
	ConvToPost(exp1);
	ConvToPost(exp2);
	ConvToPost(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);

	return 0;
}