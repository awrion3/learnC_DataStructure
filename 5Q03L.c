#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

//change this for data type
typedef int Data;

//linked list node
typedef struct node {
	Data data;
	struct node* next;
} Node;

//linked list head
typedef struct head {
	Node* head;
} Head;

//stack top datatype
typedef Head Stack;
///////////////////////////

//stack function
void SInit(Stack* ps) {
	ps->head = NULL;	//
}

int SEmpty(Stack* ps) {
	return (ps->head == NULL);
}

void SPush(Stack* ps, Data data) 
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //

	newNode->data = data;
	newNode->next = ps->head;

	ps->head = newNode;	//new top
}

Data SPop(Stack* ps) {
	Data rdata;
	Node* rNode;

	if (SEmpty(ps)) {
		exit(1);
	}
	
	rdata = ps->head->data;
	rNode = ps->head;

	ps->head = ps->head->next;	//new top
	free(rNode);
	
	return rdata;
}

Data SPeek(Stack* ps) {

	if (SEmpty(ps)) {
		exit(1);
	}

	return ps->head->data;
}

int main(void) 
{
	int num, val, tmp;
	
	Stack stack1, stack2;

	SInit(&stack1), SInit(&stack2);

	scanf("%d", &num);

	for (int i = 0; i < num; i++){		
		scanf("%d", &val);
		
		SPush(&stack1, val);
	}

	if (SEmpty(&stack2) && !SEmpty(&stack1)) 
	{	//push in to stack2
		SPush(&stack2, SPop(&stack1));
	}
	
	while (!SEmpty(&stack1)) 
	{
		tmp = SPop(&stack1);
	
		while (!SEmpty(&stack2) && tmp > SPeek(&stack2)) //stack2: top must be smallest
		{			
			SPush(&stack1, SPop(&stack2));	//pop out and push in
		}

		SPush(&stack2, tmp);	
	}
	
	while (!SEmpty(&stack2))
	{
		printf("%d ", SPop(&stack2));	//stack == print top first
	}

	return 0;
}