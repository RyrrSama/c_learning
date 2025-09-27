#ifndef collections_h
#define collections_h // Header guard

#include "queue.h"
#include "stack.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"

extern const int JUNK_VALUE;

/**
 * @brief Assigns junk values to a stack.
 *
 * This function assigns junk values to the elements of the stack
 * from the specified start index to the end index.
 *
 * @param self A pointer to the Stack.
 * @param startIndex The starting index from which junk values will be assigned.
 * @param endIndex The ending index up to which junk values will be assigned.
 */
void assignJunkValueToStack(Stack *self, int startIndex, int endIndex);

/**
 * @brief Assigns junk values to a queue.
 *
 * This function assigns junk values to the elements of the queue
 * from the specified start index to the end index.
 *
 * @param self A pointer to the Queue.
 * @param startIndex The starting index from which junk values will be assigned.
 * @param endIndex The ending index up to which junk values will be assigned.
 */
void assignJunkValueToQueue(Queue *self, int startIndex, int endIndex);

#pragma GCC diagnostic pop

#endif // collections_h
