#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//b c d e f g h l m n o p q r s t u v w x y z

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

void insertB(struct node** h) {

	int v;
	printf("Data: ");
	scanf("%d", &v);

	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->data = v;

	if (*h == NULL)
	{
		p->prev = NULL;
		p->next = NULL;

		*h = p;
	}
	else
	{
		p->prev = NULL;
		p->next = *h;

		(*h)->prev = p;
		*h = p;
	}
}

void insertM(struct node** h)
{
	if (*h == NULL) {
		printf("No Node Yet\n");
		return;
	}
	else if ((*h)->next == NULL) {
		printf("Only One Node, Use insertB or insertE instead\n");
		return;
	}
	else
	{
		int v;
		printf("Data: ");
		scanf("%d", &v);

		struct node* p = (struct node*)malloc(sizeof(struct node));
		p->data = v;

		int m;
		printf("Insert after this value: ");
		scanf("%d", &m);

		struct node* t = *h;

		while (t->next != NULL) {
			if (t->data == m)
				break;
			t = t->next;
		}

		if (t == NULL) {
			printf("Out of Range\n");
			return;
		}
		else if (t->next == NULL)
		{
			printf("Inserting at Last Node Position. Use insertE instead\n");
			return;
		}
		else
		{
			p->next = t->next;
			p->prev = t;

			t->next->prev = p;
			t->next = p;
		}
	}
}

void insertE(struct node** h) {

	int v;
	printf("Data: ");
	scanf("%d", &v);

	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->data = v;

	if (*h == NULL)
	{
		p->prev = NULL;
		p->next = NULL;

		*h = p;
	}
	else if ((*h)->next == NULL)
	{
		(*h)->next = p;

		p->prev = *h;	//
		p->next = NULL;
	}
	else
	{
		struct node* t = *h;

		while (t->next != NULL)
		{
			t = t->next;
		}

		t->next = p;

		p->prev = t;
		p->next = NULL;
	}
}

void deleteB(struct node** h)
{
	if (*h == NULL)
		printf("No Node to Delete\n");
	else if ((*h)->next == NULL)
	{
		struct node* t = *h;
		*h = NULL;
		free(t);
	}
	else {
		struct node* t = *h;
		*h = (*h)->next;
		(*h)->prev = NULL; ////
		free(t);
	}
}

void deleteM(struct node** h)
{
	if (*h == NULL) {
		printf("No Node to Delete\n");
		return;
	}
	else if ((*h)->next == NULL) {
		printf("Only One Node to Delete. Use deleteB or deleteE instead\n");
		return;
	}

	int m;
	printf("Delete after this value: ");
	scanf("%d", &m);

	struct node* t = *h;

	while (t->next != NULL) {
		if (t->data == m)
			break;
		t = t->next;
	}

	if (t == NULL)
		printf("Data Out of Range\n");
	else
	{
		if (t->next == NULL) {
			printf("Position Out of Range\n");
		}
		else if (t->next->next == NULL)
		{
			struct node* p = t->next;

			t->next = NULL;

			free(p);
		}
		else
		{
			struct node* p = t->next;	//will be deleted

			t->next = t->next->next;

			p->next->prev = t;

			free(p);
		}
	}
}

void deleteE(struct node** h)
{
	if (*h == NULL)
	{
		printf("No Node to Delete\n");
	}
	else if ((*h)->next == NULL)
	{
		struct node* t = *h;
		*h = NULL;
		free(t);
	}
	else
	{
		struct node* t = *h;

		while (t->next != NULL)
		{
			t = t->next;
		}

		struct node* p = t;	//will be deleted

		t->prev->next = NULL;

		free(p);
	}
}

void search(struct node* h) {

	if (h == NULL) {
		printf("No Node Yet\n");
		return;
	}

	int k, f = 0, x = 0;
	printf("Input data you want to find: ");
	scanf("%d", &k);

	struct node* t = h;

	while (t != NULL) ///
	{
		if (t->data == k)
		{
			f = 1;
			break;
		}
		t = t->next;
		x++;
	}

	if (f)
		printf("Your Data is at Index: %d\n", x);
	else
		printf("No Matching Data Found\n");
}

void display(struct node* h)
{
	struct node* t = h;

	if (t == NULL)
	{
		printf("No Node Yet\n");
		return;
	}

	while (t != NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}

int main(void) {

	int c;
	int i;
	struct node* l = NULL;

	do
	{
		printf("0. Finish 1. Insert 2. Delete 3. Search 4. Display: ");
		scanf("%d", &c);

		switch (c) {
		case 0:
			exit(0);
			break;
		case 1:
			printf("1) Beg 2) Mid 3) End: ");
			scanf("%d", &i);

			if (i == 1) {
				insertB(&l);
			}
			else if (i == 2) {
				insertM(&l);
			}
			else if (i == 3) {
				insertE(&l);
			}
			else {
				printf("Wrong Input\n");
			}
			break;
		case 2:
			printf("1) Beg 2) Mid 3) End: ");
			scanf("%d", &i);
			if (i == 1) {
				deleteB(&l);
			}
			else if (i == 2) {
				deleteM(&l);
			}
			else if (i == 3) {
				deleteE(&l);
			}
			else {
				printf("Wrong Input\n");
			}
			break;
		case 3:
			search(l);
			break;
		case 4:
			display(l);
			break;
		default:
			printf("Wrong Choice\n");
		}
	} while (c);

	return 0;
}