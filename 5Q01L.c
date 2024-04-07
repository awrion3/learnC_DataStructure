#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

//global (auto null)
struct node* top, * ntop, * tmp;
int cnt = 0;

void push(int data)
{
	if (top == NULL) {
		top = (struct node*)malloc(1 * sizeof(struct node));
		top->next = NULL;
		top->data = data;
	}
	else {
		tmp = (struct node*)malloc(1 * sizeof(struct node));
		tmp->next = top;
		tmp->data = data;
		top = tmp;
	}
	cnt++;

	printf("ok\n");		//
}

int pop()
{
	int rdata;

	if (top == NULL) {
		return -1;
	}
	else {
		ntop = top->next;
		rdata = top->data;

		free(top);
		top = ntop;
		cnt--;

		printf("ok\n");	//

		return rdata;
	}
}

void print()
{
	ntop = top;

	while (ntop != NULL) {
		printf("%d ", ntop->data);	//
		ntop = ntop->next;
	}

	printf("\n");
}

int main(void) {

	char opt[6];
	int val;

	scanf("%s", opt);

	while (opt != '\0') {

		if (strcmp(opt, "push") == 0) {
			scanf("%d", &val);
			push(val);
		}
		else if (strcmp(opt, "pop") == 0) {
			pop();
		}
		else if (strcmp(opt, "print") == 0) {
			print();
		}
		else if (strcmp(opt, "end") == 0) {
			printf("bye\n");
			exit(0);
		}
		scanf("%s", opt);
	}

	return 0;
}
