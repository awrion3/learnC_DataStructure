#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
//globals
int queue[SIZE]; //init to zeros
int front = -1, rear = -1;

void enqueue(int item) 
{
	if (front == -1 && rear == -1) {
		front = rear = 0;
		queue[rear] = item;
	}
	else if ((rear + 1) % SIZE == front) { //check if isFull
		printf("OVERFLOW\n"); 
	}
	else {
		rear = (rear + 1) % SIZE;
		queue[rear] = item;
	}
}

int dequeue() 
{
	int data;

	if (front == -1 && rear == -1) {	//check if isEmpty
		printf("UNDERFLOW\n");
		return -1;
	}
	else if (front == rear) {
		data = queue[front];
		front = rear = -1;
	}
	else {
		data = queue[front];
		front = (front + 1) % SIZE;
	}

	return data;
}

void display() 
{
	printf("Displaying circular queue data\n");

	if (front == -1 && rear == -1){
		printf("No data yet\n");
		return;
	}

	int i = front;
	while (i != rear) {
		printf("%d ", queue[i]);
		i = (i + 1) % SIZE;
	}
	//to flush last data (front == rear position)
	printf("%d", queue[i]);	
	printf("\n");
}

int main(void) {

	int choice, item;

	do {
		printf("Choice: 1. Enqueue 2. Dequeue 3. Display 0. Finish\n");
		scanf("%d", &choice);

		switch(choice) {
		case 0:
			exit(0);
		case 1:
			printf("Input item: ");
			scanf("%d", &item);
			enqueue(item);
			break;
		case 2:
			item = dequeue();
			printf("Output item: %d\n", item);
			break;
		case 3:
			display();
			break;
		default:
			printf("Wrong Input\n");
		}
	}
	while (choice);

	return 0;
}