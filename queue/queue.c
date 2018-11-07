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
	q->storage = malloc(capacity * sizeof(int));
	q->capacity = capacity;
	q->length = 0;

	return q;

}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
	if(q->capacity == q->length){
		int new_size = q->capacity+(sizeof(int)); 		//new size, increase capacity to accomodate new item
		q->storage=(int *)resize_memory(q->storage, q->capacity, new_size);   	// resize memory

	} 
	q->storage[q->length]=item;
	q->length ++; 

}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
	if(q->length ==0) {
		return -1;
	}	
	else{
	int result = q->storage[0];
	
	int len = (int)q->length;    //casting unsigned int to int 

	for(int i=0; i<len-1; i++){
		q->storage[i] = q->storage[i+1];
	}


	q->length --;
	return result;
	}
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
	if(q->storage) free(q->storage);
	if(q) free(q);
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    //printf("%d\n", enqueue(q, 1));	
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
