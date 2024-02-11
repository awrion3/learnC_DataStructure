#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];	//피벗의 위치는 가장 왼쪽으로 설정
	int low = left + 1;		//피벗을 제외하고 지정
	int high = right;

	while (low <= high) {			//두 지점이 교차되지 않을 때까지 반복
		//피벗보다 크거나 같은 값을 찾는 과정 (크면 반복 중지)
		while (pivot >= arr[low] && low <= right) 
			low++;

		//피벗보다 작거나 같은 값을 찾는 과정 (작으면 반복 중지)
		while (pivot <= arr[high] && high >= (left + 1)) 
			high--;

		if (low <= high)			//교차되지 않은 상태인 경우, 두 지점의 값을 교환
			Swap(arr, low, high);
	}

	Swap(arr, left, high);		//left(피벗)과 high가 가리키는 대상을 교환

	return high;	//옮겨진 피벗의 위치 정보 반환	//이후 이를 기준으로 왼쪽과 오른쪽 영역으로 나뉨
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {							//재귀 반복 조건
		int pivot = Partition(arr, left, right);	//둘로 영역을 나누어

		QuickSort(arr, left, pivot - 1);			//왼쪽 영역 정렬
		QuickSort(arr, pivot + 1, right);			//오른쪽 영역 정렬
	}
}

int main(void) {

	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
//	int arr[3] = { 3, 3, 3 };

	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);	//두 인자 인덱스 전달

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}