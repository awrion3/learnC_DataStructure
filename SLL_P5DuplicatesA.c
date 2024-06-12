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

//func remove duplicates (SL is already sorted!!!)
void duplicateSL(struct node* head) 
{
	struct node* curr = head;
	struct node* temp = head;

	while (curr->next != NULL) {
		//if curr's data == curr->next's data
		if (curr->data == curr->next->data) {	
			temp = curr->next->next;
			
			free(curr->next);	//delete curr->next's data

			curr->next = temp;	//update curr->next to curr->next->next
		}
		else {	//if no duplicates,
			curr = curr->next;	//move to next node
		}
	}

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

	//create SL with duplicates (already sorted)
	struct node* list = createSL(10);
	list->next = createSL(20);
	list->next->next = createSL(30);
	list->next->next->next = createSL(30);
	list->next->next->next->next = createSL(40);

	//display original SL
	displaySL(list);

	//remove duplicates and display result
	duplicateSL(list);
	displaySL(list);

	return 0;
}