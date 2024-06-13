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

	if (*head == NULL)
	{
		*head = newNode;
		newNode->next = NULL;
	}
	else
	{
		struct node* temp = *head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = NULL;
	}
}

//func remove duplicate
void delDup(struct node* head) 
{
	struct node* curr = head;
	struct node* temp;
	struct node* dupNode;

	if (curr == NULL)
		return;
	
	while (curr->next != NULL)  //
	{
		temp = curr;
		while (temp->next != NULL) ///
		{
			if (curr->data == temp->next->data) //
			{
				dupNode = temp->next;
				temp->next = temp->next->next; ///
				free(dupNode);
			}
			else {
				temp = temp->next;
			}		
		}
		curr = curr->next;
	}
}

//func display
void display(struct node* head)
{
	struct node* temp = head;

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
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

	delDup(head);
	display(head);

	return 0;
}