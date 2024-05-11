#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)	//

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

		while (temp->next != *head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = *head;
	}
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
	} while (temp != head);
}

//func insert element
void insertEl(struct node* head) 
{
	int data, pos;

	scanf("%d", &data);
	scanf("%d", &pos);

	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;

	if (head == NULL) {
		return;
	}

	struct node* temp = head;
	for (int i = 1; i < pos; i++) 
	{
		if (temp->next != head) 
		{
			temp = temp->next;
		}
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

int main(void) {

	int num, data;

	struct node* head = NULL;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		insert(&head, data);
	}

	insertEl(head);	
	display(head);

	return 0;
}