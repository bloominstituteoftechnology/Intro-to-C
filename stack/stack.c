#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    // array for storage
    int *storage;
    // unsigned can hold more positive than neg values
    unsigned int capacity;
    unsigned int length;
} Stack;

/*
    Creates a stack by allocating the appropriate amount of memory for an
    instance of the Stack struct, and initializes all of the fields of the
    struct. Also allocates memory for the stack's storage structure. 
*/
Stack *createStack(unsigned int capacity)
{
    Stack *stack = malloc(sizeof(Stack));

    // (*stack).length = -1;
    stack->length = -1;
    stack->capacity = capacity;

    stack->storage = malloc(capacity * sizeof(int));

    return stack;
}

int isFull(Stack *stack)
{
    return stack->length == stack->capacity -1;
}

int isEmpty(Stack *stack)
{
    return stack->length == -1;
}

/*
    Pops and returns top value of the Stack.
*/
int pop(Stack *stack)
{
    int res;

    if (isEmpty(stack))
    {
        printf("Stack is empty.");
        res = -1;
    } else {
        res = stack->storage[stack->length];
        // decrease length var so that we cannot access returned value
        stack->length--;
    }

    return res;
}



void push(Stack *stack, int value)
{
    if (isFull(stack)){
        printf("Cannot add stack is full.");
        return;
    }

    //increment length
    stack->length++;

    stack->storage[stack->length] = value;

}



/*
    Free the stack and it's storage.
*/
void destroyStack(Stack *stack)
{
    free(stack->storage);
    free(stack);
}

int main(void)
{
    Stack *stack = createStack(4);   

    push(stack, 69);
    push(stack, 2);
    push(stack, 4);
    push(stack, 102);

    printf("\n%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));

    return 0;
}