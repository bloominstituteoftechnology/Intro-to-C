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
    Queue *a_queue = malloc(sizeof(Queue));
    a_queue->length = 0;
    a_queue->capacity = capacity;
    a_queue->storage = malloc(sizeof(int) * capacity);;

    return a_queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (q->length <= q->capacity) {
        unsigned int add_capacity = q->capacity + 1;
        void *add_storage = resize_memory(q->storage, q->capacity, sizeof(int) * add_capacity);
        q->capacity = add_capacity;
        q->storage = add_storage;
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
    if (q->storage[0] == '\0'){
        return -1;
    }
    else {
        int item = q->storage[0];
        if (q->length > 1) {
            for (unsigned int index = 0; index < q->length-1; index++) {
                q->storage[index] = q->storage[index+1];
            }
        }
    q->length--;
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

    destroyQueue(q);

    return 0;
}
#endif