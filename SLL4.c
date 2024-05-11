#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//struct def
struct node {
	int data;
	struct node* next;
};

//func create node
struct node* createSL(int data) 
{
	struct node* node = (struct node*)malloc(sizeof(struct node));

	node->data = data;
	node->next = NULL;

	return node;
}

//func merge node (SL must be sorted before)
struct node* mergeSL(struct node* head1, struct node* head2) 
{
	//if either SL is empty, return other SL
	if (head1 == NULL) 
		return head2;
	if (head2 == NULL)
		return head1;

	struct node dummy;
	struct node* temp = &dummy;

	while (head1 && head2)	//means != NULL
	{
		if (head1->data < head2->data) { //merge in ascending order
			temp->next = head1;		//links node with smaller data
			head1 = head1->next;	//move to next node
		}
		else {
			temp->next = head2;
			head2 = head2->next;	//
		}
		temp = temp->next;	//move to link next node
	}
	
	//if either SL not fully traversed, append remaining nodes (since its already sorted)
	temp->next = head1 ? head1 : head2;	

	return dummy.next;	//returns first node (excepts dummy node)
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

	//simple creation of two sorted SL
	struct node* list1 = createSL(10);
	list1->next = createSL(20);
	list1->next->next = createSL(50);
	list1->next->next->next = createSL(70);

	struct node* list2 = createSL(30);
	list2->next = createSL(40);
	list2->next->next = createSL(60);

	//display two lists
	displaySL(list1);
	displaySL(list2);

	//merge two lists in ascending order, and display result
	struct node* result = mergeSL(list1, list2);
	displaySL(result);

	return 0;
}