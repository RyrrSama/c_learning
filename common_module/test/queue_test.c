#include "collections.h"
#include <stdio.h>

int main()
{
    Queue queue;
    queue_initialize(&queue);
    queue.queue_create(&queue, 5);
    queue.enQueue(&queue, 1);
    queue.enQueue(&queue, 2);
    queue.enQueue(&queue, 3);
    queue.enQueue(&queue, 4);
    queue.deQueue(&queue);
    queue.deQueue(&queue);
    queue.deQueue(&queue);
    queue.deQueue(&queue);
    queue.deQueue(&queue);
    queue.enQueue(&queue, 5);
    queue.enQueue(&queue, 6);
    queue.queue_display(&queue);
    queue.queue_destroy(&queue);
    return 0;
}