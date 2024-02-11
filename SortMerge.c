#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {	//정렬된 두 영역을 하나로 병합
	int fIdx = left;
	int rIdx = mid + 1;

	//병합한 결과를 담을 배열 sortArr의 동적 할당
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {	//인덱스 범위 만족하는 동안//
		if (arr[fIdx] <= arr[rIdx])			//병합할 두 영역의 데이터를 서로 비교한 후,
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];	
		sIdx++;								//정렬 순서대로 배열 sortArr에 하나 옮겨 담기
	}

	if (fIdx > mid) {	//앞부분이 모두 배열 sortArr에 옮겨진 경우,
		for (int i = rIdx; i <= right; i++, sIdx++)		//뒷부분에 남은 데이터를 배열로 그대로 옮기기
			sortArr[sIdx] = arr[i];
	}
	else {				//뒷부분이 모두 배열 sortArr에 옮겨진 경우,
		for (int i = fIdx; i <= mid; i++, sIdx++)		//앞부분에 남은 데이터를 배열로 그대로 옮기기
			sortArr[sIdx] = arr[i];
	}

	for (int i = left; i <= right; i++)	//정렬된 결과로 덮어씌우기
		arr[i] = sortArr[i];

	free(sortArr);						//임시 배열 동적할당 해제
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {	//더 나눌 수 있는 경우
		//중간지점 계산
		mid = (left + right) / 2;
		
		//둘로 나눠서 각각을 정렬
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		//정렬된 두 배열을 병합
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void) {

	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);	//두 인자 인덱스 전달

	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}