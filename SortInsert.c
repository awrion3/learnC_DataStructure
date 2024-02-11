#include <stdio.h>

void InsertSort(int arr[], int n) {
	int insData; int j;

	for (int i = 1; i < n; i++) {
		insData = arr[i];				//정렬 대상을 저장

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];	//한칸씩 비교 대상을 뒤로 이동
			else
				break;					//삽입 위치 찾았으므로 비교 탈출	
		}

		arr[j + 1] = insData;	//해당 위치에 정렬 대상 삽입
	}
}

int main(void) {

	int arr[5] = { 5, 3, 2, 4, 1 };

	InsertSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}