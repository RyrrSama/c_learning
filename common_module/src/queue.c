#include "queue.h"
#include "collections.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void queue_initialize(Queue *self, int size)
{
    self->data  = (int *) malloc(size * sizeof(int));
    self->size  = size;
    self->front = 0;
}

void enQueue(Queue *self, int element)
{
    if (queue_isFull(self))
    {
        // TODO: Need to Dynamically resize the Queue
        printf("ERROR: The Queue is full can't add more elements.");
    }
    self->data[self->front] = element;
    self->front++;
}

int deQueue(Queue *self)
{
    if (queue_isEmpty(self))
    {
        printf("ERROR: The Queue is empty can't remove elements.");
        return -1; // Indicate failure to remove element
    }
    int frontElement        = self->data[self->front];
    self->data[self->front] = JUNK_VALUE;
    self->front--;
    return frontElement;
}

int peek(const Queue *self)
{
    return self->data[self->front];
}

bool queue_isEmpty(const Queue *self)
{
    return (self->front < 0) ? true : false;
}

bool queue_isFull(const Queue *self)
{
    return (self->front >= self->size - 1) ? true : false;
}

void queue_display(const Queue *self)
{
    for (int index = self->front; index >= 0; index--)
    {
        printf("Queue index %d element %d", index, self->data[index]);
    }
}

void queue_destroy(Queue *self)
{
    free(self->data);
    self->front = -1;
    self->size  = 0;
}