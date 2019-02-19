#include <stdio.h>
#include <stdlib.h>
// #include "lib.h"

typedef struct Queue {
    // int top;
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
    Queue *queue = malloc(sizeof(Queue));
    queue->storage = (int *)malloc(capacity * sizeof(int));
    queue->length = 0;
    queue->capacity = capacity;
    
    return queue;
}

int isFull(Queue *queue){

    return queue->capacity == queue->length;

}

void mem_copy(void *dest, const void *src, int n)
{
    char *newDest = (char *)dest;
 
    const char *newSource =(const char*)src;
 
    while(n) 
    {
   
     *(newDest++)= *(newSource++); 
     --n;

    }

    dest = newDest;
}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{
    void *res_ptr = malloc(new_size);

    if (old_size < new_size){
        mem_copy(res_ptr, ptr, old_size);
    }

    if (old_size > new_size){
        mem_copy(res_ptr, ptr, new_size);
    }

    return res_ptr;

}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (isFull(q)){
        q->storage = (int*)realloc(q->storage, q->capacity);
    }

    q->storage[q->length] = item;
    q->length++;
    
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    int return_val = -1;

    if (q->length != 0)
    {
        return_val = q->storage[0];
        q->length--;
        q->storage++;
    }

    return return_val;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    // free(q->storage);
    free(q);
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 11);
    enqueue(q, 22);
    enqueue(q, 33);
    enqueue(q, 44);
    enqueue(q, 55);
    enqueue(q, 66);

    // for (int i = 1; i <= q->length; i++){
    //     printf("%d\n", q->storage[i]);
    // }
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