#ifndef stack_h
#define stack_h

#include <stdbool.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"

typedef struct Stack
{
    int *data;
    int top;
    int size;
    // Create a stack
    void (*stack_create)(struct Stack *self, int size);
    // Check if the stack is empty
    bool (*stack_isEmpty)(const struct Stack *self);
    // Check if the stack is full
    bool (*stack_isFull)(const struct Stack *self);
    // Push the element into the stack
    void (*stack_push)(struct Stack *self, int element);
    // Pop the element from the stack
    int (*stack_pop)(struct Stack *self);
    // Display the elements of the stack
    void (*stack_display)(const struct Stack *self);
    // Resize the stack
    int (*stack_reSize)(struct Stack *stack, int resizeLenght);
    // Destroy the stack
    void (*stack_destory)(struct Stack *self);
} Stack;

// functions
void stack_create(Stack *self, int size);
bool stack_isEmpty(const Stack *self);
bool stack_isFull(const Stack *self);
void stack_push(Stack *self, int element);
int stack_pop(Stack *self);
void stack_display(const Stack *self);
void stack_destory(Stack *self);
int stack_reSize(Stack *stack, int resizeLenght);

#pragma GCC diagnostic pop
#endif