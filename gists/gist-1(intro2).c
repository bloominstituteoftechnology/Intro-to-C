/*
heap - long living data


-> to access struct members
reduce(arr, length, initial, cb)


int reduce(int *args
)
*/


#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
  // a storage array
  int *storage;
  unsigned int capacity;
  unsigned int length;
} Stack;

// create an instance of our Stack
Stack *createStack(unsigned int capacity)
{
  // allocate some memory for our Stack instance
  Stack *stack = malloc(sizeof(Stack));
  (*stack).length = -1;
  (*stack).capacity = capacity;
  (*stack).storage = malloc(capacity * sizeof(int));

  return stack;
}

void destroyStack(Stack *stack)
{
  // First deallocate any struct members that had allocated memory
  free(stack->storage);
  // Then deallocate the actual struct
  free(stack);
}

int isFull(Stack *stack)
{
  return stack->length == stack->capacity - 1;
}

// Add elements to our Stack
void push(Stack *stack, int item)
{
  // check to see if we have available room in our storage
  if (isFull(stack)) {
    printf("Stack is full!\n");
    return;
  }

  stack->length++;
  stack->storage[stack->length] = item;
}

int isEmpty(Stack *stack)
{
  return stack->length == -1;
}

// remove an element from the top of our Stack
int pop(Stack *stack)
{
  // check to see if the Stack is empty
  if (isEmpty(stack)) {
    return -1;
  }

  int rv = stack->storage[stack->length];
  stack->length--;

  return rv;
}

int main(void)
{
  Stack *stack = createStack(3);
  push(stack, 90);
  push(stack, 24);
  push(stack, 78);
  push(stack, 98);

  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));

  destroyStack(stack);

  return 0;
}

