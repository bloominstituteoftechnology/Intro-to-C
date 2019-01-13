#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length; // current length
    unsigned int capacity; // max length
    int *storage; // is this an array of ints from 0 to length?
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *q = malloc(sizeof(Queue));

    q->capacity = capacity;
    q->length = 0;
    int *storage = malloc(capacity * sizeof(int));
    q->storage = storage;
    return q;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (q->length >= q->capacity) {
        q->capacity++;
    }

    q->storage[q->length] = item;
    q->length++;
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
    // If the lengh is equal to 0, nothing to deque, return -1
    if (q->length == 0){
        return -1;
    }

    // Store the removed item
    int removed = q->storage[0];
    // Get the length
    int len = q->length;

    // Remove the item
    for (int i = 0; i < len; i++){
        q->storage[i] = q->storage[i + 1];
    }

    // Resize length
    q->length--;

    // Return the removed item
    return removed;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    free(q->storage);
    free(q);
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

    destroyQueue(q);

    return 0;
}
#endif