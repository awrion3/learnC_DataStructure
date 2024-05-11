#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct node {
	int data;
	struct node* next;
};

struct node* insertCL(struct node* head, int data) 
{	
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;

	if (head == NULL)
	{//create first node
		//update head pointer
		head = newNode;			
		//make circular
		newNode->next = head;	
	}
	else 
	{
		int loc;
		printf("Insert Location: 1. Beg / 2. Mid / 3. End\n");
		scanf("%d", &loc);
		
		if (loc == 1) 
		{
			//insert new node at beg
			newNode->next = head;	

			struct node* temp = head;

			while (temp->next != head) 
			{
				temp = temp->next;
			}
			//make circular
			temp->next = newNode;	
			//update head pointer
			head = newNode;	
		}
		else if (loc == 2) 
		{
			int pos;
			printf("2. Mid - Insert Position in Index?:\n");
			scanf("%d", &pos);

			struct node* temp = head;

			for (int i = 1; i < pos; i++) 
			{
				if (temp->next != head) {
					temp = temp->next;
				}
			}
			//insert new node at mid
			newNode->next = temp->next;	//
			//link old node
			temp->next = newNode;
		}
		else if (loc == 3) 
		{
			struct node* temp = head;

			//traverse till last node
			while (temp->next != head) {
				temp = temp->next;
			}
			//make circular
			newNode->next = head;
			//insert new node at end
			temp->next = newNode;
		}
	}
	return head;
}

struct node* deleteCL(struct node* head) /////
{
	if (head == NULL)
	{//no node available
		printf("No node yet\n");
		return NULL;
	}
	else
	{
		int loc;
		printf("Delete Location: 1. Beg / 2. Mid / 3. End\n");
		scanf("%d", &loc);

		if (loc == 1)
		{
			struct node* temp = head;
			
			if (temp->next == head) {	//one node
				head = NULL;
			}
			else {
				while (temp->next != head)
				{
					temp = temp->next;
				}				
				//delete node at beginning;
				head = head->next;
				//make circualr update
				temp->next = head;
			}
		}
		else if (loc == 2)
		{
			int pos;
			printf("2. Mid - Delete Position in Index?:\n");
			scanf("%d", &pos);

			struct node* temp = head;

			for (int i = 1; i < pos; i++)
			{
				if (temp->next != head) //
					temp = temp->next;	
			}
			//delete node at middle
			temp->next = temp->next->next;
		}
		else if (loc == 3)
		{
			struct node* temp = head;
			struct node* prev = NULL;

			while (temp->next != head) {
				prev = temp;		//save previous node
				temp = temp->next;
			}
			//delete node at end
			prev->next = temp->next;	//prev->next = head;
		}
	}
	return head;
}

int countCL(struct node* head) 
{
	struct node* temp = head->next;

	int cnt;

	if (head == NULL)	//no node	
		return 0;
	else				//one node
		cnt = 1;

	while (head != temp) {	//at least two nodes
		temp = temp->next;	
		cnt++;
	}
	
	return cnt;	
}

void displayCL(struct node* head)
{
	struct node* curr = head;
	int cnt;

	cnt = countCL(head);

	while (cnt) {	//use cnt
		printf("%d ", curr->data);
		curr = curr->next;
		cnt--;
	}
	printf("\n");
}

void searchCL(struct node* head, int data) 
{	
	int index = 0;
	struct node* curr = head;

	int cnt;
	cnt = countCL(head);

	while (cnt) {
		if (curr->data == data) {
			printf("Your data is at index: %d\n", index);
			break;
		}
		index++;	//increase index
		curr = curr->next;
		cnt--;
	}
}

int main(void) 
{
	int opt, data, cnt;
	struct node* head = NULL;

	do {
		printf("0. Finish / 1. Insert / 2. Delete / 3. Display / 4. Count / 5. Search\n");
		scanf("%d", &opt);

		switch (opt) {
		case 1:
			printf("Input node data: ");
			scanf("%d", &data);
			head = insertCL(head, data);
			break;
		case 2:
			head = deleteCL(head);
			break;
		case 3:
			displayCL(head);
			break;
		case 4:
			cnt = countCL(head);
			printf("Total nodes at CLL is: %d\n", cnt);
			break;
		case 5:
			printf("Input search data: ");
			scanf("%d", &data);
			searchCL(head, data);
			break;
		default:
			exit(0);
		}
	} while (opt);
	
	return 0;
}