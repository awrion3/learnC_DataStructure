#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//def struct
struct node {
	int data;
	struct node* next;
};

//func insert
void insert(struct node** head, int data) 
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;

	if (*head == NULL) {
		*head = newNode;
		newNode->next = *head;
	}
	else {
		struct node* temp = *head;

		while (temp->next != *head)	//
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = *head;
	}
}

//func reverse
struct node* reverse(struct node* head) 
{
	struct node* curr = head;

	if (curr == NULL)
		return NULL;

	struct node* prev = NULL;
	struct node* temp;

	do {
		temp = curr->next;	//
		
		curr->next = prev;  
		prev = curr;		

		curr = temp;		//
	} while (curr != head);		//circular style
	head = prev;

	struct node* last = head;
	//to make circular
	while (last->next != NULL)	//single style
	{
		last = last->next;
	} 
	last->next = head; //before, this was front node

	return head;
}

//func display
void display(struct node* head) 
{
	struct node* temp = head;

	if (temp == NULL)
		return;

	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);	//circular style
}

int main(void) {

	int num;
	scanf("%d", &num);

	int data;
	struct node* head = NULL;

	for (int i = 0; i < num; i++) 
	{
		scanf("%d", &data);
		insert(&head, data);
	}

	struct node* result = NULL;
	result = reverse(head);
	display(result);

	return 0;
}