#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//

int main(void) {

	char tmp[101];
	int ten, len;

	gets(tmp);

	ten = strlen(tmp);

	len = ten / 2;
	
	if (ten % 2 != 0)
		len += 1;

	printf("%d", len);

	return 0;
}

/*
if array is given,

int arr[] = {1, 3, 5, 6, 4, 2};
int size = sizeof(arr) / sizeof(arr[0]);

printf("Size of the array: %d\n", size);
*/