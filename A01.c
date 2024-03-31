#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int x = 0, y = 0, arr[] = { 10,20,30,20,20,50,60,10 };
	printf("Elements are= ");
	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			if (arr[x] == arr[y] && x != y)
				break;
		}
		if (y == 8)
		{
			printf("%d ", arr[x]);
		}
	}
	printf("\n");
	return 0;
}
