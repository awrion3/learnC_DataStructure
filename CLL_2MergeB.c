#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)	//two CLL to one CLL

//def struct
struct node {
	int data;
	struct node* next;
};

//func insertC
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

//func displayC
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

//func sortC
void sort(struct node* head)
{
	struct node* curr = head;
	struct node* temp;
	int tval;

	while (curr->next != head)
	{
		temp = curr->next;
		while (temp != head)
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

//func merge (two cll to one cll)
struct node* merge(struct node* head1, struct node* head2)
{
	struct node* temp1 = head1;
	struct node* temp2 = head2;

	if (temp1 == NULL)
		return head2;
	if (temp2 == NULL)
		return head1;

	struct node dummy;
	struct node* result = &dummy;

	int flag = 0;
	do {
		if (temp1->data <= temp2->data)
		{
			result->next = temp1;
			temp1 = temp1->next;
			
			if (temp1 == head1) {
				flag = 2;	//cross
				break;
			}
		}
		else
		{
			result->next = temp2;
			temp2 = temp2->next;
			
			if (temp2 == head2) {
				flag = 1;	//
				break;
			}	
		}
		result = result->next;
	} while (temp1 != head1 || temp2 != head2);	
	  //it is possible that one temp is not moved at all (&& not recommended)

	if (flag == 1) {
		do {	//traverse remains
			result = result->next;	//should be first (do...while)
			result->next = temp1;
			temp1 = temp1->next;
		} while (temp1 != head1);
	}
	if (flag == 2) {
		do {	//
			result = result->next;	//
			result->next = temp2;
			temp2 = temp2->next;
		} while (temp2 != head2);
	}

	result->next->next = dummy.next; //same as result = result->next; and then this line

	return dummy.next;
}

int main(void) {

	int num, data;

	struct node* head1 = NULL;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		insert(&head1, data);
	}
	sort(head1);
	
	struct node* head2 = NULL;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		insert(&head2, data);
	}
	sort(head2);

	struct node* result = NULL;
	result = merge(head1, head2);
	display(result);

	return 0;
}