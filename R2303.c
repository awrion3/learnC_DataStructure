#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
//3
//Write a C program to add or concatenate two strings.

int main(void) {

	char str[10], btr[10];
	char res[20];

	scanf("%s", str);
	scanf("%s", btr);

	strcpy(res, str);
	strcat(res, btr);

	printf("%s", res);

	return 0;
}