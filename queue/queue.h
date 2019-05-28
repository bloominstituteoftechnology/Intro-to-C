#ifndef stack_h
#define stack_h

typedef struct Queue {
    unsigned int length;
    unsigned capacity;
    unsigned int front;
    unsigned int rear;
    int *storage;
} Queue;

Queue *createQueue(unsigned capacity);

void enqueue(Queue *q, int item);

int dequeue(Queue *q);

void destroyQueue(Queue *q);

#endif