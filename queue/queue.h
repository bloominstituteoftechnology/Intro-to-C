#ifndef stack_h
#define stack_h

typedef struct Queue {
    unsigned int length;
    unsigned capacity;
    int *storage;
} Queue;

Queue *createQueue(unsigned capacity);

void enqueue(Queue *q, int item);

int dequeue(Queue *q);

void destroyQueue(Queue *q);

#endif