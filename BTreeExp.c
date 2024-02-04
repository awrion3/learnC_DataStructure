#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //
#include <ctype.h>
#include "StackBT.h" //
#include "BTreeT.h" 

//수식 트리 구성:
//후위 표기법 수식을 입력받아 수식 트리 구성 후, 수식 트리의 루트 노드 주소값 반환
BTreeNode* MakeExpTree(char exp[]) {
	Stack stack;		//스택 생성
	BTreeNode* pnode;	//루트 노드 생성
	int expLen = strlen(exp);	//후위 표기법 기반 문자열 길이 구하기
	StackInit(&stack);	//스택 초기화

	for (int i = 0; i < expLen; i++) {
		pnode = MakeBTreeNode();	//노드 생성 및 연결 초기화

		if (isdigit(exp[i])) {		//피연산자면
			SetData(pnode, exp[i] - '0');	//해당 피연산자 문자를 정수로 바꾸어 노드에 저장
		}
		else {						//연산자면
			MakeRightSubTree(pnode, SPop(&stack));	//스택의 맨위 연산자 서브 트리의 오른쪽에 저장
			MakeLeftSubTree(pnode, SPop(&stack));	//스택의 아래 연산자 서브 트리의 왼쪽에 저장
			SetData(pnode, exp[i]);			//해당 연산자 문자를 노드에 저장
		}

		SPush(&stack, pnode);		//만든 서브 트리 혹은 노드를 스택에 쌓기
	}

	return SPop(&stack);			//최종 수식 트리를 스택에서 꺼내기
}

//수식 트리 계산:
int EvalExpTree(BTreeNode* bt) {
	int op1, op2;
	
	//재귀 탈출 조건
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);		//단말 노드라면, 해당 피연산자 데이터 반환

	//재귀적으로 구성 (단말 노드가 아닌 서브 트리라면, 해당 서브 트리의 루트 노드 기준으로 하여)
	op1 = EvalExpTree(GetData(GetLeftSubTree(bt)));		//첫번째 피연산자(왼쪽) 
	op2 = EvalExpTree(GetData(GetRightSubTree(bt)));	//두번째 피연산자(오른쪽)

	switch (GetData(bt)) {		//연산자에 따라 계산 결과 반환
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}

	return 0;	//기본은 0 반환
}

//수식 트리 출력 방법:
void ShowNodeData(int data) {		//출력 기능 구현 함수
	if (0 <= data && data <= 9)	//정수인 경우
		printf("%d ", data);
	else						//문자(연산자)인 경우
		printf("%c ", data);
}

//전위 표기법 기반 출력(전위 순회 관련)
void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);	//두번째 인자로 action함수 등록
}

//중위 표기법 기반 출력(중위 순회 관련)
void ShowInfixTypeExp(BTreeNode* bt) {
	InorderTraverse(bt, ShowNodeData);
}

//후위 표기법 기반 출력(후위 순회 관련)
void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}