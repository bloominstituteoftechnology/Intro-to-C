#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length;
    unsigned int capacity;
    unsigned int front;
    unsigned int rear;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->capacity = capacity;
    newQueue->length = 0;
    newQueue->front = 0;
    newQueue->rear = 0;

    newQueue->storage = malloc(sizeof(int) * capacity);
    
    printf("Storage pointer in createQueue: %p\n", newQueue->storage);
    return newQueue;
}

int isEmpty(Queue *q) {
    return q->length == 0;
}

int isFull(Queue *q) {
    return q->length == q->capacity;
}

void printQueue(Queue *q) {
    printf("Front: %d, Rear: %d, Capacity: %d, Length: %d\n", q->front, q->rear, q->capacity, q->length);
    printf("[ ");
    for (unsigned int i = 0; i < q->capacity; i++) {
        printf("%d, ", q->storage[i]);
    }
    printf(" ]\n\n");
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (isFull(q)) {
        // Add more storage
        q->rear += q->capacity;
        q->capacity *= 2;
        q->storage = resize_memory(q->storage, q->capacity);
    }
    q->storage[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
    q->length += 1;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if (isEmpty(q)) {
        return -1;
    } else {
        int item = q->storage[q->front];
        q->front = (q->front + 1) % q->capacity;
        
        q->length += -1;
        return item;
    }

}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->storage != NULL) {
        free(q->storage);
    }

    if (q != NULL) {
        free(q);
    }
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif