#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "../malloc/malloc.h"

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
     Queue *q = malloc(sizeof( Queue));

     q->capacity= capacity;
     q->length = 0;

     q->storage = malloc(capacity*sizeof(int));
    return q;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if(q->capacity <=q->length){
        q = resize_memory(q, q->capacity, (q->capacity + 1));
        q->capacity += 1;
    }
    q->storage[q->length] = item;
    q->length += 1;
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
    
    if(q->storage == NULL){
        return -1;
    }
    int returnVal = q->storage[0];
    for(unsigned int i=1;i<q->length;i++){
        q->storage[i-1] = q->storage[i];
    }
    q->length -= 1;
    return returnVal;
    

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