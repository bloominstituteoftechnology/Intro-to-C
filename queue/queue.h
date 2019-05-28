#ifndef stack_h
#define stack_h

typedef struct Queue {
    unsigned int length;
    unsigned capacity;
    int *storage;
} Queue;

Queue *createQueue(unsigned capacity);

int dequeue(Queue *q);

void destroyQueue(Queue *q);
void enqueue(Queue *q, int item);


#endif