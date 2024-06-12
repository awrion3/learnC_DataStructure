#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//func counter
int counter(struct node* head)
{
	int cnt = 0;
	struct node* temp = head;

	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}

	return cnt;
}

int main(void) {

	int len;
	char str[100], tmp[100];

	gets(str);						//includes ' '
	len = strlen(str);

	for (int i = 0; i < len; i++) 
	{
		if (str[i] == ' ')
			str[i] = '\0';
	}

	struct node* head = NULL;
	int data;

	for (int i = 0; i < len;) 
	{
		if (str[i] != '\0') 
		{
			strcpy(tmp, str + i);	//each string

			data = atoi(tmp);		//turn to integer
			insert(&head, data);

			i += strlen(tmp);	//
		}
		else {
			i++;				//
		}
	}
	
	int cnt;
	cnt = counter(head);
	printf("%d", cnt);

	return 0;
}