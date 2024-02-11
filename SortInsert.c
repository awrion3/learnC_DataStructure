#include <stdio.h>

void InsertSort(int arr[], int n) {
	int insData; int j;

	for (int i = 1; i < n; i++) {
		insData = arr[i];				//���� ����� ����

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];	//��ĭ�� �� ����� �ڷ� �̵�
			else
				break;					//���� ��ġ ã�����Ƿ� �� Ż��	
		}

		arr[j + 1] = insData;	//�ش� ��ġ�� ���� ��� ����
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