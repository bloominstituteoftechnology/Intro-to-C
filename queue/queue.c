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
    queue->capacity = capacity;
    queue->storage = malloc(capacity);
    return queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (q->length == q->capacity) {
        // q->capacity += 1;
        // q->storage = realloc(q->storage, q->capacity);
        q->storage = resize_memory(q->storage, q->length, q->length + 1);
        q->capacity += 1;
    }
    *(q->storage + q->length) = item;
    q->length += 1;
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
    if (q->length == 0) {
        return -1;
    }
    int value = *(q->storage);
    int a[q->length - 1];
    int count = 1;
    for (unsigned int i = 0; i < q->length - 1; i++) {
        a[i] = *(q->storage + count);
        count++;
    }
    q->storage = resize_memory(q->storage, q->length, q->length - 1);
    q->length -= 1;
    for (unsigned int i = 0; i < q->length; i++) {
        *(q->storage) = a[i];
    }
    return value;
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
    if(q != NULL) {
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

    printf("%d\n", q->length);
    for (unsigned int i = 0; i < q->length; i++) {
        printf("%d\n", *(q->storage + i));
    }

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