#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *queue = malloc(sizeof(Queue));

    queue -> length = 0;
    queue -> capacity = capacity;
    queue -> storage = malloc(capacity * sizeof(int));

    return queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (q -> length == q -> capacity) {
        q -> capacity++;
        int *temporary = malloc(q -> capacity * sizeof(int));
        for (int i = 0; i <= q -> length; i++) {
            temporary[i] = q -> storage[i];
        }
        free(q -> storage);
        q -> storage = temporary;
    } 

    q -> length++;
    q -> storage[q -> length] = item;
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
    int item;

    if (q -> length > 0) {
    item = q -> storage[1];
    // Shift items
    for (int i = 0; i < q -> length; i++) {
        q -> storage[i] = q -> storage[i + 1];
    }
    q -> length--;
    } else {
    item = -1;
    }

    return item;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q -> storage != NULL) {
        free(q -> storage);
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