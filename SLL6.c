#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//struct def
struct node {
	int data;
	struct node* next;
};

//func create node (adding from front) (also without return value)
void createFSL(struct node** head, int data)	//if **, no need to return * to update?
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;	//update head pointer
}

//func merge cross node (also without return value)
void mergeCSL(struct node** head1, struct node** head2) //double pointer
{
	struct node* list1 = *head1;
	struct node* list2 = *head2;

	while (list1 != NULL && list2 != NULL) 
	{
		struct node* temp = list1->next;	//temporary save

		list1->next = list2;		//merge list2 node

		list2 = list2->next; //move to next node in list2

		list1->next->next = temp;	//merge list1 node

		list1 = temp;		//prepare to move to next node in list1
	}

	*head2 = list2;	//plus: update list2 head pointer to remaining list2 nodes
}

//func display
void displaySL(struct node* head)
{
	struct node* temp = head;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(void) {

	struct node* head1 = NULL;
	struct node* head2 = NULL;

	//create two lists (adding from front)
	createFSL(&head1, 1);	//sending the address of head node
	createFSL(&head1, 3);	//*head address **struct address
	createFSL(&head1, 5);
	createFSL(&head1, 7);
	createFSL(&head1, 9);

	createFSL(&head2, 2);
	createFSL(&head2, 4);
	createFSL(&head2, 6);
	createFSL(&head2, 8);
	createFSL(&head2, 10);

	//display two lists
	displaySL(head1);	   //*struct address	
	displaySL(head2);

	//merge cross two lists and display result
	mergeCSL(&head1, &head2);
	displaySL(head1);
	//plus
	displaySL(head2);

	return 0;
}