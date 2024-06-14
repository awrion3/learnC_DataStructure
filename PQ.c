#pragma warning(disable:4996)
#include<stdio.h>
#include<limits.h>

#define MAX 100

// denotes where the last item in priority queue is
// initialized to -1 since no item is in queue
int idx = -1;

// pqValue holds data for each index item
// pqPriority holds priority for each index item
int pqValue[MAX];
int pqPriority[MAX];

int isEmpty() {
    return idx == -1;
}

int isFull() {
    return idx == MAX - 1;
}

//enqueue simply adds item based on Priority (if Max == High)
void enqueue(int data, int priority, int value)
{
    if (!isFull())
    {
        if (idx == -1) //First element | O(1)
        {
            idx++;  // Increase the index
            // Insert the element in priority queue
            pqValue[idx] = data;
            pqPriority[idx] = priority;
        }
        else
        {
            idx++;  // add one elem space
            for (int i = idx - 1; i >= 0; i--) {  // careful with index range
                // ignores same pri == FCFS, max pri num == high pri
                if (pqPriority[i] < priority) { 
                    // one right shift elems with low pri 
                    pqValue[i + 1] = pqValue[i];        
                    pqPriority[i + 1] = pqPriority[i];   
                }
                //range started from idx - 1, thus +1 needed
                else {
                    pqValue[i + 1] = value;           
                    pqPriority[i + 1] = priority;
                    break;
                }
            }
        }
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        printf("Dequeued data: %d\n", pqValue[0]);
        // reduce size of priority queue by first
        // shifting all elements one position left
        for (int i = 1; i < idx; i++)
        { // consider idx range
            pqValue[i] = pqValue[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
        // reduce size of priority queue by 1
        idx--;
    }
}
