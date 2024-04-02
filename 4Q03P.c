#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)
#define MAX_LEN 100

typedef struct {
	int top;
	char** items;
} stack;

//
void init(stack* s) {
	s->top = -1;
	s->items = (char**)malloc(MAX_LEN * sizeof(char*));	
	//point an array with MAX_LEN elements of char* type
}

void push(stack* s, char* item) {
	if (s->top == MAX_LEN - 1) {
		printf("OVERFLOW\n");
		exit(1);
	}
	s->top++;	//careful with order
	s->items[s->top] = item;
}

char* pop(stack* s) {
	char* sexp;

	if (s->top == -1) {
		printf("UNDERFLOW\n");
		exit(1);
	}
	sexp = s->items[s->top];
	s->top--;

	return sexp;
}

//
int isOperand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main(void) { //POST to INFIX using Stack
	char postfix[MAX_LEN];
	stack s;

	scanf("%s", postfix);
	init(&s);

	for (int i = 0; i < strlen(postfix); i++) {
		if (!isOperand(postfix[i])) {	//if operand, make operand to string, then push to stack
			char* item = (char*)malloc(2 * sizeof(char));
			
			item[0] = postfix[i];
			item[1] = '\0';

			push(&s, item);
		}
		else {	//if operator, pop operands, combine with operator, push expression to stack
			char* nitem = (char*)malloc(2 * sizeof(char));

			nitem[0] = postfix[i];
			nitem[1] = '\0';

			char* oprnd1 = pop(&s);
			char* oprnd2 = pop(&s);

			char* item = (char*)malloc(1 + (strlen(oprnd2) + 1 + strlen(oprnd1) + 1 + 1) * sizeof(char));
			item[0] = '\0';

			strcpy(item, "(");
			strcat(item, oprnd2);
			strcat(item, nitem);
			strcat(item, oprnd1);
			strcat(item, ")");
			//sprintf(item, "(%s%c%s)", oprnd2, postfix[i], oprnd1);

			push(&s, item);
		}
	}

	char* infix = pop(&s);
	printf("%s", infix);

	//
	for (int i = 0; i < s.top; i++) {
		free(s.items[i]);
	}
	free(s.items);

	return 0;
}
//