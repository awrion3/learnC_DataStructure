#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//def struct
struct node {
	int data;
	struct node* next;
};

//func insert (only at end)
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

//func finder
int finder(struct node* head, int item) 
{
	int index = 1;
	struct node* temp = head;

	while (temp->next != NULL) 
	{
		if (temp->data == item)
			return index;
		temp = temp->next;
		index++;
	}

	return -1;
}

int main(void) {
	
	int num, data;	
	scanf("%d", &num);	

	struct node* head = NULL;

	for (int i = 0; i < num; i++) 
	{
		scanf("%d", &data);
		insert(&head, data);
	}

	int item, index;

	scanf("%d", &item);
	index = finder(head, item);

	if (index == -1)
		printf("error");
	else
		printf("%d", index);

	return 0;
}