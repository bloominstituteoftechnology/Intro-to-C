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
  int *storage = malloc(sizeof(int) * capacity);
  q->storage = storage;

  return q;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
  // printf("enqueueing %d\n", item);
  if (q->length == q->capacity) {
    // printf("new capacity needed\n");
    // int *scratch = q->storage;
    int *new_storage = malloc(sizeof(int) * q->capacity + 1);
    unsigned int i;
    for (i = 0; i < q->length; i++) {
      new_storage[i] = q->storage[i];
    }
    new_storage[i] = item;
    q->storage = new_storage;
    q->capacity = (q->capacity + 1);
  } else {
    // printf("going into old capacity\n");
    q->storage[q->length] = item;
  }
  q->length ++;
  // printf("length is %u\ncapacity is %u\n", q->length, q->capacity);
}

/*
    Removes the item at the front of the queue. If the queue is empty,
    this function should return -1.
*/
int dequeue(Queue *q)
{
  if ((int)q->length > 0) {
    int item = q->storage[0];
    int *temp_storage = q->storage;
    for (unsigned int i = 0; i < q->length; i++) {
      temp_storage[i] = q->storage[i+1];
    }
    q->storage = temp_storage;
    q->length --;
    // printf("Dequeuing item: %d\n Length: %u\n", item, q->length);

    return item;
  } else {
    // printf("length = 0\n");
    return -1;
  }
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage.
*/
void destroyQueue(Queue *q)
{
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
