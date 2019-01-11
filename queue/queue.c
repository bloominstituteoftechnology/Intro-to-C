#include <stdio.h>
#include <stdlib.h>
#include "lib.h" // resize_memory function import

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
  Queue *newQueue = malloc(sizeof(Queue)); // allocates memory for size of a struct Queue
  newQueue->length=0; // current total of items in queue and also position tracker in storage
  newQueue->capacity=capacity; // max number of items the queue can hold
  newQueue->storage=malloc(sizeof(int)*capacity); // allocates memory according to capacity needed
  return newQueue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
  // TWO
  if (q->length == q->capacity) // if tracker reaches the capacity (end of queue)
  {
    q->capacity++; // update capacity to reflect new increase need
    q->storage = resize_memory(q->storage, sizeof(int) * (q->capacity)); // resize memory based on need
  }
  q->storage[q->length] = item; // insert item at that tracker position
  q->length++; //advance the tracker position

  // ONE
  // if (q->length < q->capacity) // if the tracker is not at the end of the queue
  // {
  //   q->storage[q->length] = item; // insert the item at that tracker in storage
  //   q->length++; // advance the tracker
  // }
  // else if (q->length == q->capacity) // if tracker reaches the capacity
  // {
  //   void *new_storage = resize_memory(q->storage, q->capacity, sizeof(int) * (q->capacity+1)); //create new storage +1 capacity
  //   q->storage = new_storage; // update the old pointer 
  //   q->capacity++; // update capacity to reflect increase
  //   q->storage[q->length] = item; // insert item at that tracker
  //   q->length++; //advance the tracker
  // }
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
  if (q->length == 0) // if the queue is empty, tracker position at 0
  {
    return -1;
  }
  else if (q->length > 0)
  {
    int original = q->storage[0]; // necessary to store the original int item before the shift occurs
    for (unsigned int i=0; i < q->length-1; i++) // advance all the pointers
    {
      q->storage[i] = q->storage[i+1]; // moves pointer in storage by 1
    }
    q->length--; // decrease length by 1 due to dequeue operation
    return original; // returns the value that was dequeued
  }
  return 0;
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