#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  // Create a storage array
  int *storage;

  // Unsigned can be ....
  unsigned int capacity;
  unsigned int length;

} Stack;

Stack *createStack (unsigned int capacity) {
  // allocate some memory for our Stack instance
  Stack *stack = malloc(sizeof(Stack)); // #include stdlib
  
  // Crate an empty stack
  stack->length = -1;
  // (*stack).length = -1;
  stack->capacity = capacity;
  // (*stack).capacity = capacity

  // malloc space for the storage
  stack->storage = malloc(capacity * sizeof(int));

  return stack;
}


// Need to free memory for our storage and stack
void destroyStack(Stack *stack) {
  // First deallocate any struct members that had allocated memory
  free(stack->storage)
  // Then free the stack
  free(stack)
}

int isFull(Stack *stack) {
  return stack->length == stack->capacity - 1;
}

void push(Stack *stack, int item) {
  if(isFull(stack)){
    printf("Stack is full\n");
    return
  }

  stack->length++;
  stack->storage[stack->length] = item;
}