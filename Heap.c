#include "Heap.h" //

//���� �ʱ�ȭ//
void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

//���� ������� Ȯ��//
int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

//�θ� ����� �ε��� �� ��ȯ
int GetParentIDX(int idx) {
	return idx / 2;
}

//���� �ڽ� ����� �ε��� �� ��ȯ
int GetLChildIDX(int idx) {
	return idx * 2;
}

//������ �ڽ� ����� �ε��� �� ��ȯ
int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

//���ڷ� ���޵� ����� �� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
int GetHiPriChildIDX(Heap* ph, int idx) {

	//�ܸ� ����� (�������� �ʴ�) ���� �ڽ� ��� �ε��� ���� ���� ��, ���� ����� ��� ���� �Ѿ�� ��*
	if (GetLChildIDX(idx) > ph->numOfData)			//�ڽ� ��尡 ���� ���*
		return 0;	//*���� ���� ���� Ʈ���⿡ �ܸ� ����̸�, 

	//���� �ڽ� ��尡 �� ���� ������ ��尡 �ǹǷ�*
	else if (GetLChildIDX(idx) == ph->numOfData)	//�ڽ� ��尡 �ϳ�(����)�� ���*
		return GetLChildIDX(idx);
	
	//pr�� �������� �켱���� ����*
	else {											//�ڽ� ��尡 ���� ���*
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)	
			return GetRChildIDX(idx);	//������ �ڽ� ��尡 �켱������ ���� ��� 
		else
			return GetLChildIDX(idx);	//���� �ڽ� ��尡 �켱������ ���� ���
	}
}

//���� ������ ����//������ ��带 �߰��ϰ�, �θ� ������ (�켱����) �񱳸� ���� ���
void HInsert(Heap* ph, HData data, Priority pr) {
	int idx = ph->numOfData + 1;		//�߰��� �� ��尡 ����� �ε��� ���� ����
	HeapElem nelem = { pr, data };		//�� ����� ���� �� ���޹��� �����ͷ� �ʱ�ȭ

	//�� ��尡 ����� ��ġ�� ��Ʈ ����� ��ġ�� �ƴϸ� ��� �ݺ�
	while (idx != 1) {
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {	//�� ��尡 �� ����� �θ� ��庸�� �켱������ ���ٸ�
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];	//�θ� ��带 �� ���� ������ ����
			idx = GetParentIDX(idx);	   //�� ��带 �� ���� �ø� (�����δ� �ƴϰ�, �ε��� ����)
		}
		else		//�� ����� �켱������ �θ� ��庸�� ���� ���� ��� �ݺ� ����
			break;
	}

	ph->heapArr[idx] = nelem;	//�� ��带 ������ �ش� ��ġ�� ����
	ph->numOfData++;			//������ ��ü ���� �ϳ� ����
}

//���� ������ ����//��Ʈ ��� ����, ������ ���� ä���, �ڽ� ������ �񱳸� ���� �ϰ�
HData HDelete(Heap* ph) {
	HData retData = (ph->heapArr[1]).data;			//������ ������ ����(���� ��Ʈ ����� ������ ����)
	HeapElem lastElem = ph->heapArr[ph->numOfData]; //����ü ���� �ʱ�ȭ(���� ������ ��� ����)

	int parentIdx = 1;	//��Ʈ ��尡 ��ġ�ؾ� �� �ε��� �� ����(��Ʈ ��� ������ ������ ��尡 ���⿡ �ӽ� ��ġ�ϴ� ��)
	int childIdx;	

	//�ݺ��� ��, parentIdx���� ������ ��尡 ����� ��ġ ������ ���� ��
	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) { //��Ʈ ����� �켱������ ���� �ڽ� ��忡�� �ݺ��� ����
		if (lastElem.pr <= ph->heapArr[childIdx].pr)	 //������ ���� �ش� �ڽ� ����� �켱���� ��
			break;								//������ ����� �켱������ ������ ����(��Ʈ ��� �ڸ��� �״�� ������ ��)
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];	 //�ڽ� ��尡 �� ������, �ش� ��� ��ġ�� �� ���� �ø���(������ ��)
		parentIdx = childIdx;					//������ ����� ��ġ ������ �� ���� ����
	}	//�� ��ü�� �켱������ �����Ǿ� �ִٰ� ����

	ph->heapArr[parentIdx] = lastElem;	//������ ��尡 �ڸ��� ��ġ�� ��ħ�� ������
	ph->numOfData--;	//�� ������ �� ����

	return retData;		//������ ������ ��ȯ
}