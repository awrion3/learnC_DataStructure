#include <stdio.h>
#include "BTreeExp.h"	//

int main(void) {

	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);		//수식 트리 생성

	ShowPrefixTypeExp(eTree); printf("\n");		//전위 표기법 기반 수식 트리 출력
	ShowInfixTypeExp(eTree); printf("\n");		//중위...
	ShowPostfixTypeExp(eTree); printf("\n");	//후위...

	printf("연산 결과: %d \n", EvalExpTree(eTree));	   //수식 트리 연산 결과 출력

	return 0;
}