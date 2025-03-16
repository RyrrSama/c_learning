#ifndef collections_h
#define collections_h // Header guard

#include "queue.h"
#include "stack.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"

extern const int JUNK_VALUE;

void stack_initialize(Stack *stack);
void assignJunkValueToStack(Stack *self, int startIndex, int endIndex);
void assignJunkValueToQueue(Queue *self, int startIndex, int endIndex);

#pragma GCC diagnostic pop

#endif // collections_h
