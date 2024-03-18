#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 10

int int_arr[SIZE]; int Rear = -1; int Front = -1; //global

void enqueue(); void dequeue(); void show();

int main(void) {
    int ch;

    while (1) {
        printf("\n--1.Enqueue 2.Dequeue 3.Display 4.Exit--\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}

void enqueue() {
    int insert_item;

    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else {
        if (Front == -1)
            Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);

        Rear = Rear + 1; //first time: 0
        int_arr[Rear] = insert_item;
    }
}

void dequeue() {
    if (Front == -1 || Front > Rear) {
        printf("Underflow \n");
        return;
    }
    else {
        printf("Element deleted from the Queue: %d\n", int_arr[Front]);
        Front = Front + 1;
    }
}

void show() {
    if (Front == -1)
        printf("Empty Queue \n");
    else {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", int_arr[i]);
        printf("\n");
    }
}
