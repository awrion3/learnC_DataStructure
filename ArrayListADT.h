/*
[배열 기반 순차 리스트] 자료구조의 추상 자료형(ADT) ==
해당 자료구조가 제공하는 기능(Operation): 구현된 자료구조의 활용

1//리스트 초기화
void ListInit(List *plist);

2//데이터 저장
void LInsert(List *plist, LData data);  //LData는 typedef 선언의 결과(데이터의 자료형 자유화)

3//리스트 참조
int LFirst(List *plist, LData *pdata);	//첫번째 데이터 조회		//둘 다 성공시 1, 실패시 0 반환
										(참조된 데이터가 pdata가 가리키는 메모리에 저장됨)
int LNext(List *plist, LData *pdata);	//두번째 이후 데이터 조회
										(참조된 데이터의 다음 데이터가 ...에 저장됨)
4//데이터 삭제
LData LRemove(List *plist);		//참조 함수의 마지막으로 반환된 데이터 삭제 (삭제된 데이터를 반환)

5//데이터 개수
int LCount(List *plist);		//리스트에 저장된 데이터의 개수를 반환
*/