#include "queue.h"
#include "collections.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void reArrangeQueue(Queue *self)
{

    for (int index = self->front; index > self->rear - 1; index++)
    {
        self->data[index] = self->data[index + 1];
    }
    self->data[self->rear] = JUNK_VALUE;
}

void queue_initialize(Queue *self)
{
    self->queue_create  = queue_create;
    self->enQueue       = enQueue;
    self->deQueue       = deQueue;
    self->peek          = peek;
    self->queue_destroy = queue_destroy;
    self->queue_display = queue_display;
    self->queue_isEmpty = queue_isEmpty;
    self->queue_isFull  = queue_isFull;
}

void queue_create(Queue *self, int size)
{
    self->data        = (int *) malloc(size * sizeof(int));
    self->initizeSize = size;
    self->size        = size;
    self->front       = -1;
    self->rear        = -1;
}

void enQueue(Queue *self, int element)
{
    if (queue_isFull(self))
    {
        printf("WARNING: The Queue is full can't add more elements.\n");
        int status = queue_resize(self);
        if (status == -1)
        {
            printf(
                "ERROR: Failed to Resize queue, Memory allocation Failed.\n");
            return;
        }
    }
    self->data[++self->rear] = element;
    if (self->front == -1)
    {
        self->front++;
    }
}

int deQueue(Queue *self)
{
    if (queue_isEmpty(self))
    {
        printf("ERROR: The Queue is empty can't remove elements.\n");
        return -1;
    }
    int frontElement = self->data[self->front];
    reArrangeQueue(self);
    self->rear = self->rear - 1;
    if (self->rear == 0) self->front = -1;
    return frontElement;
}

int peek(const Queue *self)
{
    if (queue_isEmpty(self))
        return -1;
    else
        return self->data[self->front];
}

bool queue_isEmpty(const Queue *self)
{
    return (self->front == -1 && self->rear == -1) ? true : false;
}

bool queue_isFull(const Queue *self)
{
    return (self->rear >= self->size - 1) ? true : false;
}

int queue_resize(Queue *self)
{
    int *tempPtr = (int *) realloc(
        self->data, ((self->size + self->initizeSize) * sizeof(int)));
    if (tempPtr == NULL)
    {
        return -1;
    }
    else
    {
        self->data = tempPtr;
        self->size += self->initizeSize;
    }
    return 0;
}

void queue_display(const Queue *self)
{
    for (int index = self->front; index <= self->rear; index++)
    {
        printf("Queue index %d element %d\n", index, self->data[index]);
    }
}

void queue_destroy(Queue *self)
{
    free(self->data);
    self->size  = 0;
    self->front = -1;
    self->rear  = -1;
}
