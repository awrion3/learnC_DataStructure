#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)	//Lab6-6 two SLL to one CLL

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

//func sort
void sort(struct node* head)
{
	struct node* curr = head;
	struct node* temp;
	int tval;

	while (curr != NULL)
	{
		temp = curr->next;
		while (temp != NULL)
		{
			if (curr->data > temp->data)
			{
				tval = curr->data;
				curr->data = temp->data;
				temp->data = tval;
			}
			temp = temp->next;
		}
		curr = curr->next;
	}
}

//func mergeC
struct node* mergeC(struct node* head1, struct node* head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	struct node* temp1 = head1;
	struct node* temp2 = head2;

	struct node dummy;
	struct node* result = &dummy;

	while (temp1 && temp2)
	{
		if (temp1->data <= temp2->data)
		{
			result->next = temp1;
			temp1 = temp1->next;
		}
		else
		{
			result->next = temp2;
			temp2 = temp2->next;
		}
		result = result->next;
	}

	result->next = temp1 ? temp1 : temp2;

	//make it circular
	while (result->next != NULL) 
	{
		result = result->next;
	}
	result->next = dummy.next;

	return dummy.next;
}

//func displayC
void displayC(struct node* head)
{
	struct node* temp = head;

	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);
}

int main(void) {

	int num1, num2, data;

	struct node* head1 = NULL;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &data);
		insert(&head1, data);
	}
	sort(head1);

	struct node* head2 = NULL;
	scanf("%d", &num2);

	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &data);
		insert(&head2, data);
	}
	sort(head2);

	struct node* result = NULL;
	result = mergeC(head1, head2);
	displayC(result);

	return 0;
}