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
    //setting up space on heap for the que
    Queue *que = malloc(sizeof(Queue));
    que->length = 0;
    que->capacity = capacity;
    //setting up space on heap for storage
    que->storage = malloc(sizeof(int)* capacity);
    return que;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    //if the ques length is currently at its companity
    //I change its current storage size in memeory to change it to capacity
    if (q-> length == q->capacity){
        q->storage = resize_memory(q->storage, q->capacity, q->capacity);
    }
    //here I take the storage and I increase it by 1
    // and set its value to the item passed in
    q->storage[q->length++] = item;
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/

int dequeue(Queue *q)
{
    //if I try to run the dequeue function it will end with a negative number
    if(q->length == 0){
        return -1;
    }

    //set a variable equal to the firest element in storage
    int remove = q->storage[0];

    //here I reshuffle all the values in ques storage to repare for the next
    //time this function is used
    for(unsigned int i = 1; i < q->length;i++){
        q->storage[i-1] = q->storage[i];
    }
    //subtract the length of q
    q->length--;
    //return the removed value for printf
    return remove;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    //here I free up the space from storage 
    //first because if I free q first I can't access storage to free up
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