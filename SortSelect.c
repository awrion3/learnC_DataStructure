#include <stdio.h>

void SelectSort(int arr[], int n) {
	int maxIdx, temp;

	for (int i = 0; i < n - 1; i++) {
		maxIdx = i;	//최대 인덱스 범위

		for (int j = i + 1; j < n; j++) {

			if (arr[j] > arr[maxIdx]) {	//최소값 탐색
				maxIdx = j;
			}
		}

		temp = arr[i];					//데이터의 교환
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main(void) {

	int arr[4] = { 3, 2, 4, 1 };

	SelectSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}