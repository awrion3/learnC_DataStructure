#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//strlen();

#define SIZE 100
int top = -1;
char arr[SIZE];

void push(char ch) {

	if (top == SIZE - 1) {
		printf("Overflow!\n");
	}
	else {
		top += 1;
		arr[top] = ch;
	}
}

char pop() {
	char ch;

	if (top == -1) {
		printf("Underflow!\n");
		return 0;
	}
	else {
		ch = arr[top];
		top -= 1;

		return ch;
	}
}

int main(void) {

	char tmp[SIZE] = { 0 }, rev[SIZE] = { 0 };
	int i = 0;
	
	scanf("%s", tmp);

	for (int i = 0; i < strlen(tmp); i++) {
		push(tmp[i]);
	}
	
	while (top != -1) {
		rev[i++] = pop();
	}
	
	printf("%s", rev);

	return 0;
}