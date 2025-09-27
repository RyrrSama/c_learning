#include "circularQueue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void circularQueue_create(circularQueue *queue, int size)
{
    queue->data     = (int *) malloc(size * sizeof(size));
    queue->front    = -1;
    queue->rear     = 0;
    queue->size     = size;
    queue->capacity = size;
}

void circularQueue_enqueue(circularQueue *queue, int element)
{
    if (circularQueue_isFull(queue))
    {
        // TODO: Dynamically increase the size of circular queue
        printf("WARNING queue is full, Cant able to add element to stack.");
        return;
    }
    queue->data[queue->rear] = element;
    if (queue->front == -1) queue->front = 0;

    if ((queue->front != 0) && (queue->rear == queue->size - 1))
        queue->rear = 0;
    else if ((queue->front == 0) && (queue->rear == queue->size - 1))
    {
        printf("ERROR: Cant able to add new element to stack.");
        return;
    }
    else
        queue->rear++;
}

int circularQueue_dequeue(circularQueue *queue)
{
    if (circularQueue_isEmpty(queue)) return -1;
    int frontElement = queue->data[queue->front];
    queue->front =
        ((queue->rear < queue->front) && (queue->front == queue->size - 1))
            ? 0
            : queue->front--;
    return frontElement;
}

int circularQueue_peek(const circularQueue *queue)
{
    return queue->data[queue->front];
}

bool circularQueue_isEmpty(const circularQueue *queue)
{

    return !circularQueue_isFull(queue);
}

bool circularQueue_isFull(const circularQueue *queue)
{

    return ((queue->front + queue->rear) >= queue->capacity - 1) ? true : false;
}

void circularQueue_display(const circularQueue *queue)
{
    int index = queue->front;
    while (index != queue->rear)
    {
        if (index == queue->size) index = 0;
        printf("Index : %d, Element : %d", index, queue->data[index]);
        index++;
    }
}

void circularQueue_destroy(circularQueue *queue)
{
    free(queue->data);
    queue->data     = NULL;
    queue->size     = 0;
    queue->capacity = 0;
    queue->front    = -1;
    queue->rear     = 0;
}