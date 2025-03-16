#include "collections.h"
#include "queue.h"
#include "stack.h"

const int JUNK_VALUE = -12345;

void stack_initialize(Stack *stack)
{
    stack->stack_create  = stack_create;
    stack->stack_isEmpty = stack_isEmpty;
    stack->stack_isFull  = stack_isFull;
    stack->stack_push    = stack_push;
    stack->stack_pop     = stack_pop;
    stack->stack_display = stack_display;
    stack->stack_reSize  = stack_reSize;
    stack->stack_destory = stack_destory;
}

void assignJunkValueToStack(Stack *self, int startIndex, int endIndex)
{
    for (int index = startIndex; index <= endIndex; index++)
    {
        self->data[index] = JUNK_VALUE;
    }
}

void assignJunkValueToQueue(Queue *self, int startIndex, int endIndex)
{
    for (int index = startIndex; index <= endIndex; index++)
    {
        self->data[index] = JUNK_VALUE;
    }
}