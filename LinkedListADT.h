/*
[동적할당 기반 연결 리스트] 자료구조의 ADT(추상 자료형)

1//리스트 초기화
void ListInit(List* plist);

2//리스트 데이터 저장
void LInsert(List* plist, LData pdata);

(추가: 새 노드를 추가할 때 머리와 꼬리 중 어디에 추가할 것인가?
 머리에 추가 방법 선택 시, 저장된 순서를 유지하지 않으나, 포인터 변수 tail을 사용할 필요 없음. 
 팁: 리스트는 저장된 순서를 유지해야 하는 자료구조가 아님. 
 주의: 저장 순서와 정렬 순서6를 구분해 생각!)

(변경: 노드를 앞에서부터 즉 머리에 추가하기로 했기에, 포인터 변수 tail 사용 안함.
 또한 리스트의 맨 앞에 데이터를 담지 않은 빈 더미 노드를 사용하여, 
 모든 노드가 두번째 이후 추가될 수 있도록 일관되게 구성한다.*)

3//리스트 데이터 조회
int LFirst(List* plist, LData* pdata);

int LNext(List* plist, LData* pdata);

4//리스트 데이터 삭제
LData LRemove(List* plist);

5//리스트 데이터 수 확인
int LCount(List* plist);		//...까지는 배열 기반 순차 리스트와 동일//

6//정렬 기능 추가: 리스트에 정렬 기준이 되는 함수를 등록한다//
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)); 

(추가: 두번째 인자 형식은 comp 함수 포인터로, 
 함수 포인터는 함수 이름(함수 주소값)와 연결하여 사용.
 반환형이 int이고 LData형 인자를 두개 전달받는 함수의 주소값을 전달해야 함;
 예를 들면, comp = WhoIsPrecede;)
*/