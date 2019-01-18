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
  struct Queue *q = malloc(sizeof(struct Queue));
  
  q->length = 0;
  q->capacity = capacity;
  q->storage = malloc(sizeof(int)* capacity);
  
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
    int old_cap = q->capacity;
    int new_cap = q->capacity * 2;
    q->storage = resize_memory(q->storage, old_cap, new_cap);
    q->capacity = new_cap;
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
  if (q->length == 0) {
    return -1;
  }
  int rem_item = q->storage[0];
  int length = q->length;

  for (int i = 0; i < length; i++) {
    q->storage[i] = q->storage[i + 1];
  }
  q->length--;

  return rem_item;
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