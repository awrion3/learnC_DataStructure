#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {	//���ĵ� �� ������ �ϳ��� ����
	int fIdx = left;
	int rIdx = mid + 1;

	//������ ����� ���� �迭 sortArr�� ���� �Ҵ�
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {	//�ε��� ���� �����ϴ� ����//
		if (arr[fIdx] <= arr[rIdx])			//������ �� ������ �����͸� ���� ���� ��,
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];	
		sIdx++;								//���� ������� �迭 sortArr�� �ϳ� �Ű� ���
	}

	if (fIdx > mid) {	//�պκ��� ��� �迭 sortArr�� �Ű��� ���,
		for (int i = rIdx; i <= right; i++, sIdx++)		//�޺κп� ���� �����͸� �迭�� �״�� �ű��
			sortArr[sIdx] = arr[i];
	}
	else {				//�޺κ��� ��� �迭 sortArr�� �Ű��� ���,
		for (int i = fIdx; i <= mid; i++, sIdx++)		//�պκп� ���� �����͸� �迭�� �״�� �ű��
			sortArr[sIdx] = arr[i];
	}

	for (int i = left; i <= right; i++)	//���ĵ� ����� ������
		arr[i] = sortArr[i];

	free(sortArr);						//�ӽ� �迭 �����Ҵ� ����
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {	//�� ���� �� �ִ� ���
		//�߰����� ���
		mid = (left + right) / 2;
		
		//�ѷ� ������ ������ ����
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		//���ĵ� �� �迭�� ����
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void) {

	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);	//�� ���� �ε��� ����

	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}