#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue
{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} circularQueue;

void circularQueue_create(circularQueue *queue, int size);
void circularQueue_enqueue(circularQueue *queue, int element);
int circularQueue_dequeue(circularQueue *queue);
int circularQueue_peek(const circularQueue *queue);
bool circularQueue_isEmpty(const circularQueue *queue);
bool circularQueue_isFull(const circularQueue *queue);
void circularQueue_display(const circularQueue *queue);
void circularQueue_destroy(circularQueue *queue);