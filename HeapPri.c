#include "HeapPri.h" //

//힙의 초기화//
void HeapInit(Heap* ph, PriorityComp pc) {	//우선순위 비교 함수도 등록
	ph->numOfData = 0;
	ph->comp = pc;
}

//힙이 비었는지 확인//
int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

//부모 노드의 인덱스 값 반환
int GetParentIDX(int idx) {
	return idx / 2;
}

//왼쪽 자식 노드의 인덱스 값 반환
int GetLChildIDX(int idx) {
	return idx * 2;
}

//오른쪽 자식 노드의 인덱스 값 반환
int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

//인자로 전달된 노드의 두 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap* ph, int idx) {

	//단말 노드의 (존재하지 않는) 왼쪽 자식 노드 인덱스 값을 구할 시, 힙에 저장된 노드 수를 넘어서게 됨*
	if (GetLChildIDX(idx) > ph->numOfData)			//자식 노드가 없는 경우*
		return 0;	//*힙은 완전 이진 트리기에 단말 노드이며, 

	//왼쪽 자식 노드가 곧 힙의 마지막 노드가 되므로*
	else if (GetLChildIDX(idx) == ph->numOfData)	//자식 노드가 하나(왼쪽)인 경우*
		return GetLChildIDX(idx);

	//자식 노드가 둘인 경우*
	else {	///우선순위 비교 함수에 따른 결과값에 기반하여///						
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);	//오른쪽 자식 노드가 우선순위가 높은 경우 
		else
			return GetLChildIDX(idx);	//왼쪽 자식 노드가 우선순위가 높은 경우
	}
}

//힙에 데이터 저장//마지막 노드를 추가하고, 부모 노드와의 (우선순위) 비교를 통해 상승
void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;		//추가할 새 노드가 저장될 인덱스 값을 저장
	
	//새 노드가 저장될 위치가 루트 노드의 위치가 아니면 계속 반복
	while (idx != 1) {	///우선순위 비교 함수에 따른 결과값에 기반하여///
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {	//새 노드가 새 노드의 부모 노드보다 우선순위가 높다면
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];		//부모 노드를 한 레벨 실제로 내림
			idx = GetParentIDX(idx);	   //새 노드를 한 레벨 올림 (실제로는 아니고, 인덱스 값만)
		}
		else		//새 노드의 우선순위가 부모 노드보다 높지 않은 경우 반복 종료
			break;
	}

	ph->heapArr[idx] = data;	//새 노드를 실제로 해당 위치에 저장//
	ph->numOfData++;			//데이터 전체 개수 하나 증가
}

//힙의 데이터 삭제//루트 노드 비우고, 마지막 노드로 채우고, 자식 노드와의 비교를 통해 하강
HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1];					//삭제할 데이터 저장(힙의 루트 노드의 데이터 저장)//
	HData lastElem = ph->heapArr[ph->numOfData];	//구조체 대입 초기화(힙의 마지막 노드 저장)//

	int parentIdx = 1;	//루트 노드가 위치해야 할 인덱스 값 저장(루트 노드 삭제시 마지막 노드가 여기에 임시 위치하는 셈)
	int childIdx;

	//반복문 후, parentIdx에는 마지막 노드가 저장될 위치 정보가 담기게 됨
	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) { //루트 노드의 우선순위가 높은 자식 노드에서 반복문 시작
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)	 //마지막 노드와 해당 자식 노드의 우선순위 비교
			break;								//마지막 노드의 우선순위가 높으면 종료(루트 노드 자리에 그대로 있으면 됨)

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];	 //자식 노드가 더 높으면, 해당 노드 위치를 한 레벨 올리기(데이터 상)
		parentIdx = childIdx;					//마지막 노드의 위치 정보는 한 레벨 낮춤
	}	//힙 자체의 우선순위는 고정되어 있다고 이해

	ph->heapArr[parentIdx] = lastElem;	//마지막 노드가 자리할 위치에 마침내 저장함
	ph->numOfData--;	//힙 데이터 수 감소

	return retData;		//삭제한 데이터 반환
}