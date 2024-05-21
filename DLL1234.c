#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

void insertB(struct node** head);
void insertM(struct node** head);
void insertE(struct node** head);

void deleteB(struct node** head);
void deleteM(struct node** head);
void deleteE(struct node** head);

void displayD(struct node* head);
void searchD(struct node* head);

int main(void) {

	struct node* DLL = NULL;
	int choice;
	int input;

	do {
		printf("0. Finish 1. Insert 2. Delete 3. Display 4. Search:");
		scanf("%d", &choice);

		switch (choice) 
		{
			case 1:		
				printf("1. Beg 2. Mid 3. End:");
				scanf("%d", &input);
				switch (input) 
				{
				case 1:
					insertB(&DLL);
					break;
				case 2:
					insertM(&DLL);
					break;
				case 3:
					insertE(&DLL);
					break;
				default:
					printf("Input is not valid\n");
				}
				break;
			case 2:
				printf("1. Beg 2. Mid 3. End:");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					deleteB(&DLL);
					break;
				case 2:
					deleteM(&DLL);
					break;
				case 3:
					deleteE(&DLL);
					break;
				default:
					printf("Input is not valid\n");
				}
				break;
			case 3:
				displayD(DLL);
				break;
			case 4:
				searchD(DLL);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Input is not valid\n");
		}
	} while (choice);

	return 0;
}

void insertB(struct node** head)
{
	int data;
	printf("Input Data:");
	scanf("%d", &data);

	if (*head == NULL)
	{	//No Node
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;

		*head = newNode; //
		printf("Very First Node Inserted\n");
	}
	else
	{
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = *head;

		(*head)->prev = newNode; //
		*head = newNode;	//update head
	}
}

void insertM(struct node** head) 
{
	if (*head == NULL) 
	{
		printf("No Node Yet\nUse insertB instead\n");
		return;
	}
	else if ((*head)->next == NULL) 
	{
		printf("Only One Node\nUse insertB/E instead\n");
		return;
	}
	else 
	{
		int data;
		printf("Input Data:");
		scanf("%d", &data);

		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;

		int pos;
		printf("Type insert position:");
		scanf("%d", &pos);	//insert at exact position (value in that position will be shifted to right)

		if (pos == 0)
		{
			printf("Use insertB instead\n");
			return;
		}
		else 
		{
			struct node* ptr = *head;
			
			for (int i = 1; i < pos; i++) //becareful with index
			{
				ptr = ptr->next;
			}	//becareful! ptr will be at pos - 1 //insert after ptr == pos - 1

			if (ptr->next == NULL) 
			{	//Last Node
				printf("Use insertE instead\n");
				return;
			}
			else if (ptr == NULL) 
			{	//Out of Bound
				printf("Not correct position\n");
				return;
			}
			else 
			{
				struct node* newNode = (struct node*)malloc(sizeof(struct node));
				newNode->data = data;

				newNode->next = ptr->next;	//from newNode perspective
				newNode->prev = ptr;

				ptr->next = newNode;	    //remember, ptr is before pos
				newNode->next->prev = newNode;  //link, after pos
			}
		}
	}
}

void insertE(struct node** head) 
{
	if (*head == NULL) 
	{
		printf("No Node Yet\nUse insertB instead\n");
		return;
	}
	else 
	{	//insert at End
		int data;
		printf("Input Data:");
		scanf("%d", &data);

		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;

		struct node* ptr = *head;
		while (ptr->next != NULL) 
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;

		newNode->prev = ptr;
		newNode->next = NULL;
	}
}

void deleteB(struct node** head) 
{
	if (*head == NULL) 
	{
		printf("No Node to Delete\n");
		return;
	}
	else if ((*head)->next == NULL) 
	{	//Only One Node
		struct node* temp = *head;
		*head = NULL;	//
		free(temp);
	}
	else
	{
		struct node* temp = *head;

		*head = (*head)->next;
		(*head)->prev = NULL;

		free(temp);
	}
}

void deleteM(struct node** head) 
{
	if (*head == NULL)
	{
		printf("No Node to Delete\n");
		return;
	}
	else if ((*head)->next == NULL)
	{
		printf("Only One Node\nUse DeleteB/E instead\n");
		return;
	}
	else 
	{
		int val;
		printf("Deleted after this value:");
		scanf("%d", &val);

		struct node* ptr = *head;
		while (ptr->next != NULL) 
		{
			if (ptr->data == val) //
				break;
			ptr = ptr->next;
		}

		//will delete after value, hence ptr->next
		if (ptr->next == NULL)
		{
			printf("Out of Bounds\n");
			return;
		}
		else if (ptr->next->next == NULL)
		{   //printf("Use DeleteE instead\n");
			struct node* temp = ptr->next;

			ptr->next = NULL;

			free(temp);
		}
		else 
		{   //will be deleted Node
			struct node* temp = ptr->next;	

			ptr->next = temp->next;
			temp->next->prev = ptr;

			free(temp);
		}
	}
}

void deleteE(struct node** head) 
{
	if (*head == NULL)
	{	
		printf("No Node to Delete\n");
		return;
	}
	else if ((*head)->next == NULL)
	{	//Only One Node
		struct node* temp = *head;
		
		*head = NULL;
		
		free(temp);
	}
	else 
	{
		struct node* temp = *head;

		while (temp->next != NULL) 
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;

		free(temp);
	}
}

void displayD(struct node* head) 
{
	if (head == NULL)
		printf("No Node Yet\n");
	else 
	{
		struct node* ptr = head;
		while (ptr != NULL)
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void searchD(struct node* head) 
{
	if (head == NULL)
		printf("No Node Yet\n");
	else 
	{
		int item, idx = 0, flag = 0;
		printf("Enter the item you want to find:");
		scanf("%d", &item);

		struct node* ptr = head;
		while (ptr != NULL) 
		{
			if (ptr->data == item)
			{
				flag = 1;	//
				break;
			}
			ptr = ptr->next;
			idx++;
		}

		if (flag)
			printf("Your item is at index: %d\n", idx);
		else
			printf("No item found\n");
	}
}