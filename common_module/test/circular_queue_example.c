#include "circularQueue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    circularQueue queue;
    circularQueue_create(&queue, 5);

    circularQueue_enqueue(&queue, 1);
    circularQueue_enqueue(&queue, 2);
    circularQueue_enqueue(&queue, 3);
    circularQueue_enqueue(&queue, 4);
    circularQueue_enqueue(&queue, 5);

    circularQueue_display(&queue);

    printf("Dequeued: %d\n", circularQueue_dequeue(&queue));
    printf("Dequeued: %d\n", circularQueue_dequeue(&queue));

    circularQueue_display(&queue);

    circularQueue_enqueue(&queue, 6);
    circularQueue_enqueue(&queue, 7);

    circularQueue_display(&queue);

    circularQueue_destroy(&queue);

    return 0;
}