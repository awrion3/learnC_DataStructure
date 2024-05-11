#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//구조체 정의
struct node {
	int data;
	struct node* next;
};

//함수 선언
void displaySL(struct node*);
struct node* insertSL(struct node*, int);
struct node* deleteSL(struct node*);

void sortSL(struct node*);
int searchSL(struct node*, int);
int sizeSL(struct node*);

int main(void) {

	int choice, item, index, size;
	struct node* head = NULL;

	do {
		printf("choice: 0. finish  1. insert  2. delete  3. display  4. sort  5. search  6. size\n");
		scanf("%d", &choice);
		
		if (choice == 1) {
			printf("inserting item: ");
			scanf("%d", &item);

			head = insertSL(head, item);
		}
		else if (choice == 2) {
			head = deleteSL(head);
		}
		else if (choice == 3) {
			displaySL(head);
		}
		else if (choice == 4) {
			sortSL(head);
		}
		else if (choice == 5) {
			printf("searching item: ");
			scanf("%d", &item);

			index = searchSL(head, item);

			if (index == -1)
				printf("searched item is not found\n");
			else
				printf("searched item is at index: %d\n", index);
		}
		else if (choice == 6) {
			size = sizeSL(head);
			printf("size of singly linked list: %d\n", size);
		}
		else
			break;
	} while (choice);

	return 0;
}

//함수 정의1: displaySL
void displaySL(struct node* head)
{
	int index = 0;
	struct node* temp = head;

	while (temp != NULL)	//traverse to the last node
	{
		printf("data at index %d: %d\n", index, temp->data);
		temp = temp->next;
		index++;
	}
}

//함수 정의2: insertSL
struct node* insertSL(struct node* head, int item)
{
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = item;

	if (head == NULL) //insert very first node
	{
		newNode->next = NULL;	//
		head = newNode;	//update head pointer

		printf("first node inserted\n");
	}
	else
	{
		int pos, loc;

		printf("position: 1. Beg 2. Mid 3. End\n");
		scanf("%d", &pos);
		if (pos == 2)
		{
			printf("insertion location (in index): ");
			scanf("%d", &loc);
		}

		struct node* temp = head;

		switch (pos) {
		case 1:
			newNode->next = head;	//
			head = newNode;
			break;
		case 2:
			for (int i = 1; i < loc; i++)	//excludes head
			{
				if (temp->next != NULL) {
					temp = temp->next;
				}
			}
			newNode->next = temp->next;	//
			temp->next = newNode;
			break;
		case 3:
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = NULL;	//
			break;
		}
	}
	return head;
}

//함수 정의3: deleteSL
struct node* deleteSL(struct node* head)
{
	int delData = 0;

	if (head == NULL) //no node to delete
	{
		printf("Error: No node\n");
		return NULL;
	}
	else
	{
		int pos, loc;

		printf("position: 1. Beg 2. Mid 3. End\n");
		scanf("%d", &pos);
		if (pos == 2)
		{
			printf("deletion location (in index): ");
			scanf("%d", &loc);
		}

		struct node* temp = head;

		switch (pos) {
		case 1:
			delData = head->data;
			head = head->next;
			break;
		case 2:
			for (int i = 1; i < loc; i++)	//
			{
				if (temp->next != NULL) {
					temp = temp->next;
				}
			}
			delData = temp->next->data;
			temp->next = temp->next->next;
			break;
		case 3:
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delData = temp->next->data;
			temp->next = NULL;
			break;
		}
	}
	printf("item deleted: %d\n", delData);
	return head;
}

//함수 정의4: sortSL
void sortSL(struct node* head) 
{
	int order, temp;

	struct node* curr = head;
	struct node* indx;

	printf("Sorting order: 1. ascending 2. descending\n");
	scanf("%d", &order);

	if (order == 1) {
		while (curr != NULL) 
		{
			indx = curr->next;
			while (indx != NULL) 
			{
				if (curr->data > indx->data) {	//small to front
					temp = curr->data;
					curr->data = indx->data;
					indx->data = temp;
				}
				indx = indx->next;
			}
			curr = curr->next;
		}
	}
	else if (order == 2) {
		while (curr != NULL) 
		{
			indx = curr->next;
			while (indx != NULL) 
			{
				if (curr->data < indx->data) {	//big to front
					temp = curr->data;
					curr->data = indx->data;
					indx->data = temp;
				}
				indx = indx->next;
			}
			curr = curr->next;
		}
	}
}

//함수 정의5: searchSL
int searchSL(struct node* head, int item) 
{
	int index = 0;
	struct node* temp = head;

	while (temp != NULL) 
	{
		if (temp->data == item)
			return index;
		temp = temp->next;
		index++;
	}
	return -1;
}

//함수 정의6: sizeSL
int sizeSL(struct node* head) 
{
	int size = 1;
	struct node* temp = head;

	if (head == NULL)
		return 0;

	while (temp->next != NULL) {
		temp = temp->next;
		size++;
	}

	return size;
}