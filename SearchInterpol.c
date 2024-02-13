#include <stdio.h>

int ISearch(int ar[], int first, int last, int target) {
	int s;

	if (ar[first] > target || ar[last] < target)	//Ž�� ����
		return -1;

	//������ Ž�� Ű ���ϱ�
	s = ( (double)(target - ar[first])/(ar[last] - ar[first]) * (last - first) ) + first;

	//Ž�� �������� Ű ��ȯ�ϱ�
	if (ar[s] == target)
		return s;
	else if (target < ar[s])
		return ISearch(ar, first, s - 1, target);
	else
		return ISearch(ar, s + 1, last, target);
}

int main(void) {

	int arr[] = { 1, 3, 5, 7, 9 };

	int idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ž�� Ÿ�� ���� �ε���: %d\n", idx);

	return 0;
}