#include "stack.h"
#include "collections.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void stack_create(Stack *self, int size)
{
    self->size = size;
    self->data = (int *) malloc(size * sizeof(int));
    self->top  = -1;
    assignJunkValueToStack(self, 0, size - 1);
}

bool stack_isEmpty(const Stack *self)
{
    return (self->top == -1);
}

bool stack_isFull(const Stack *self)
{
    return (self->top == self->size - 1);
}

void stack_push(Stack *self, int element)
{
    if (stack_isFull(self))
    {
        // TODO: Dynamically increase the size of Stack
        printf("Warning: Stack full, Cant able to add element to stack.\n");
        printf("INFO: Re-Sizing Stack Memory.\n");
        stack_reSize(self, self->size);
        printf("SUCCESS: Stack Re-Sized successfully.\n");
    }
    self->data[++self->top] = element;
}

int stack_pop(Stack *self)
{
    if (stack_isEmpty(self))
    {
        printf("ERROR: Stack UnderFlow Error\n");
    }
    int element           = self->data[self->top];
    self->data[self->top] = JUNK_VALUE;
    self->top--;
    return element;
}

void stack_display(const Stack *self)
{
    for (int index = self->size - 1; index >= 0; index--)
    {
        if (self->data[index] != JUNK_VALUE)
            printf("Index: %d, Value: %d\n", index, self->data[index]);
    }
}

int stack_reSize(Stack *self, int resizeLenght)
{
    self->data =
        (int *) realloc(self->data, (self->size + resizeLenght) * sizeof(int));
    if (self->data == NULL)
    {
        printf("Falied to Resize Stack.\n");
        return -1; // Memory Resize failed
    }
    assignJunkValueToStack(self, self->size, (self->size + resizeLenght - 1));
    // reArrangeStack(self, resizeLenght);
    self->size += resizeLenght;
    return 0;
}

void stack_destory(Stack *self)
{
    free(self->data);
    self->data = NULL;
    self->top  = -1;
    self->size = 0;
    printf("Deleted Stack successfully.\n");
}
