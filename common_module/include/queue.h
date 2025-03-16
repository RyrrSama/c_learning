/**
 * @file queue.h
 * @brief Header file for a Queue data structure with function pointers for
 * operations.
 *
 * This file contains the definition of a Queue data structure and declarations
 * of functions to perform various operations on the queue such as
 * initialization, enqueue, dequeue, peek, check if the queue is empty or full,
 * display the queue, and destroy the queue.
 */

#ifndef queue_h
#define queue_h

#include <stdbool.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"

/**
 * @struct Queue
 * @brief A structure to represent a queue.
 *
 * This structure contains an array to hold the data, an integer to represent
 * the front of the queue, and function pointers to perform various operations
 * on the queue.
 */
typedef struct Queue
{
    int *data; /**< Pointer to the array holding the queue elements. */
    int size;
    int front; /**< Index of the front element in the queue. */
    void (*queue_initialize)(
        struct Queue *self,
        int size); /**< Function pointer to initialize the queue. */
    void (*enQueue)(struct Queue *self,
                    const int element); /**< Function pointer to add an element
                                           to the queue. */
    int (*deQueue)(struct Queue *self); /**< Function pointer to remove an
                                     element from the queue. */
    int (*peek)(
        const struct Queue *self); /**< Function pointer to get the front
                         element of the queue without removing it. */
    bool (*queue_isEmpty)(const struct Queue *self); /**< Function pointer to
                                                 check if the queue is empty. */
    bool (*queue_isFull)(const struct Queue *self);  /**< Function pointer to
                                                 check if  the queue is full. */
    void (*queue_display)(const struct Queue *self); /**< Function pointer to
                                           display the elements of the queue. */
    void (*queue_destroy)(
        struct Queue *self); /**< Function pointer to destroy the
                         queue and free allocated memory. */
} Queue;

/**
 * @brief Initializes the queue with a given size.
 *
 * @param self Pointer to the queue structure.
 * @param size Size of the queue.
 */
void queue_initialize(Queue *self, int size);

/**
 * @brief Adds an element to the queue.
 *
 * @param self Pointer to the queue structure.
 * @param element The element to be added to the queue.
 */
void enQueue(Queue *self, const int element);

/**
 * @brief Removes an element from the queue.
 *
 * @param self Pointer to the queue structure.
 */
int deQueue(Queue *self);

/**
 * @brief Gets the front element of the queue without removing it.
 *
 * @param self Pointer to the queue structure.
 * @return The front element of the queue.
 */
int peek(const Queue *self);

/**
 * @brief Checks if the queue is empty.
 *
 * @param self Pointer to the queue structure.
 * @return true if the queue is empty, false otherwise.
 */
bool queue_isEmpty(const Queue *self);

/**
 * @brief Checks if the queue is full.
 *
 * @param self Pointer to the queue structure.
 * @return true if the queue is full, false otherwise.
 */
bool queue_isFull(const Queue *self);

/**
 * @brief Displays the elements of the queue.
 *
 * @param self Pointer to the queue structure.
 */
void queue_display(const Queue *self);

/**
 * @brief Destroys the queue and frees allocated memory.
 *
 * @param self Pointer to the queue structure.
 */
void queue_destroy(Queue *self);

#pragma GCC diagnostic pop

#endif