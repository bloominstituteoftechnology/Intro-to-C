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
    Queue *q = malloc(sizeof(Queue));
    q->capacity = capacity;
    q->length = 0;
    q->storage = malloc(sizeof(int) * capacity);
    
    return q;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{

    printf("lets enqueue: %d\n", item);
    if (q->capacity <= q->length+1) {
        //expand the queue
            //create new q, double capacity
            int new_capacity = q->capacity*2;
            Queue *new_q = createQueue(new_capacity);
            
            //copy elements in q to new q
            for (int i =0; i<q->length;i++) {
                new_q->storage[i] = q->storage[i];
            }
            
            //store new q length
            new_q->length = q->length;

            //add new element to new queue
            new_q->storage[new_q->length+1] = item;
            q->length++;
        

    } else {
    q->storage[q->length] = item;
    q->length++;
    }
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{

    if (q->storage == NULL) {
        return -1;
    }
    int item = q->storage[0];
    
   
    for (int i =1; i < q->length ; i++) {
        printf("item at index %d: %d\n", i-1);
        q->storage[i-1] = q->storage[i];
    }
    q->storage[q->length-1] = NULL;
    q->length--;

    return item;

}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->capacity != NULL) {
        free(q->capacity);
    }
    if (q->length != NULL) {
        free(q->length);
    }
    if (q->storage != NULL) {
        free(q->storage);
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

    //destroyQueue(q);

    return 0;
}
#endif