#include <stdio.h>

int ISearch(int ar[], int first, int last, int target) {
	int s;

	if (ar[first] > target || ar[last] < target)	//Å½»ö ½ÇÆÐ
		return -1;

	//µ¥ÀÌÅÍ Å½»ö Å° ±¸ÇÏ±â
	s = ( (double)(target - ar[first])/(ar[last] - ar[first]) * (last - first) ) + first;

	//Å½»ö µ¥ÀÌÅÍÀÇ Å° ¹ÝÈ¯ÇÏ±â
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
		printf("Å½»ö ½ÇÆÐ\n");
	else
		printf("Å½»ö Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);

	return 0;
}