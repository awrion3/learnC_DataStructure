#ifndef __B_TREE_EXP_H__
#define __B_TREE_EXP_H__

#include "BTreeT.h"	//

//함수 원형 선언//
//수식 트리 구성(후위 표기법 수식을 입력받아 수식 트리 구성 후, 수식 트리의 루트 노드 주소값 반환)
BTreeNode* MakeExpTree(char exp[]);
//수식 트리 계산
int EvalExpTree(BTreeNode* bt);

//수식 트리 출력 방법:
//전위 표기법 기반 출력(전위 순회 관련)
void ShowPrefixTypeExp(BTreeNode* bt);
//중위 표기법 기반 출력(중위 순회 관련)
void ShowInfixTypeExp(BTreeNode* bt);
//후위 표기법 기반 출력(후위 순회 관련)
void ShowPostfixTypeExp(BTreeNode* bt);

#endif