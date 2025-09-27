#include "collections.h"
#include "queue.h"
#include "stack.h"

const int JUNK_VALUE = -12345;

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