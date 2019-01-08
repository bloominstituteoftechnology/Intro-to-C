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
    Queue *newQueue = malloc(sizeof(Queue));

    newQueue->storage = malloc(capacity * sizeof(int));
    newQueue->length = 0;
    newQueue->capacity = capacity;

    return newQueue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if(q->length < q->capacity){ // if there's space in the queue, append the item to the end
        q->storage[q->length] = item;
        q->length += 1;
    } else {
        q->capacity += 1; // extend the capacity by 1
        q->storage = resize_memory(q->storage, q->capacity-1*sizeof(int), q->capacity * sizeof(int)); // use our resize_memory function to allocate a new storage size
        q->storage[q->length] = item;
        q->length += 1;
    }
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
    if(q->length == 0){
        return -1;
    } else {
        int i = 0;
        int item = q->storage[0];

        // this shifts all of the items in the queue up by one
        while(i < q->capacity){
            q->storage[i] = q->storage[i+1];
            i++;
        }

        q->length--; // reduce the queue length by one

        return item;
    }
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