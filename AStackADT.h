/*
(순차 리스트 기반) 스택 자료구조의 추상 자료형(ADT)가
제공하는 기능 Operations:

//1
void StackInit(Stack *pstack);
스택의 초기화를 진행

//2
int SIsEmpty(Stack *pstack);
스택이 빈 경우 1, 아닌 경우 0 반환

//3
void SPush(Stack *pstack, Data data);
스택에 데이터를 저장, 인자 data로 전달된 값을 저장

//4
Data SPop(Stack *pstack);
마지막에 저장된 요소를 삭제, 삭제된 데이터는 반환

//5
Data SPeek(Stack *pstack);
마지막에 저장된 요소를 반환만 함, 삭제하지는 않음
*/