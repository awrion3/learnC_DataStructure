#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>	//strcmp();
#include <stdlib.h>	//exit();

#define SIZE 100
int top = -1, arr[SIZE];

void push() {
	int x;

	if (top == SIZE - 1) {
		printf("Overflow!\n");
	}
	else {
		scanf("%d", &x);
		top += 1;
		arr[top] = x;
		printf("ok\n");
	}
}

void pop() {
	if (top == -1) {
		printf("Underflow!\n");
	}
	else {
		printf("%d\n", arr[top]);
		top -= 1;
	}
}

void back() {
	if (top == -1) {
		printf("Underflow!\n");
	}
	else {
		printf("%d\n", arr[top]);
	}
}

void size() {
	printf("%d\n", top + 1);
}

void clear() {
	while (1) {
		top--;
		if (top == -1)
			break;
	}
	printf("ok\n");
}

int main(void) {
	
	char order[6] = { 0 };

	scanf("%s", order);
	
	while (1) {

		if (!strcmp(order, "push")) {
			push();
		}
		else if (!strcmp(order, "pop")) {
			pop();
		}
		else if (!strcmp(order, "back")) {
			back();
		}
		else if (!strcmp(order, "size")) {
			size();
		}
		else if (!strcmp(order, "clear")) {
			clear();
		}
		else if (!strcmp(order, "exit")) {
			printf("bye\n");
			exit(0);
		}

		scanf("%s", order);
	}

	return 0;
}