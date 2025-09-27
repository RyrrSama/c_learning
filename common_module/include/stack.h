#ifndef stack_h
#define stack_h

#include <stdbool.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"

/**
 * @file stack.h
 * @brief Stack data structure and its operations.
 *
 * This file contains the definition of the Stack data structure and the
 * function pointers for various stack operations.
 */

/**
 * @struct Stack
 * @brief A structure to represent a stack.
 *
 * This structure defines a stack with an array of integers, a top index,
 * and the size of the stack. It also includes function pointers for
 * various stack operations.
 *
 * @var Stack::data
 * Pointer to the array of integers representing the stack.
 *
 * @var Stack::top
 * Index of the top element in the stack.
 *
 * @var Stack::size
 * Maximum size of the stack.
 *
 * @var Stack::stack_create
 * Function pointer to create a stack.
 *
 * @var Stack::stack_isEmpty
 * Function pointer to check if the stack is empty.
 *
 * @var Stack::stack_isFull
 * Function pointer to check if the stack is full.
 *
 * @var Stack::stack_push
 * Function pointer to push an element into the stack.
 *
 * @var Stack::stack_pop
 * Function pointer to pop an element from the stack.
 *
 * @var Stack::stack_display
 * Function pointer to display the elements of the stack.
 *
 * @var Stack::stack_reSize
 * Function pointer to resize the stack.
 *
 * @var Stack::stack_destory
 * Function pointer to destroy the stack.
 */
typedef struct Stack
{
    int *data;
    int top;
    int size;
    // Create a stack
    void (*stack_create)(struct Stack *self, int size);
    // Check if the stack is empty
    bool (*stack_isEmpty)(const struct Stack *self);
    // Check if the stack is full
    bool (*stack_isFull)(const struct Stack *self);
    // Push the element into the stack
    void (*stack_push)(struct Stack *self, int element);
    // Pop the element from the stack
    int (*stack_pop)(struct Stack *self);
    // Display the elements of the stack
    void (*stack_display)(const struct Stack *self);
    // Resize the stack
    int (*stack_reSize)(struct Stack *stack, int resizeLenght);
    // Destroy the stack
    void (*stack_destory)(struct Stack *self);
} Stack;

/**
 * @brief Initializes the stack.
 *
 * This function initializes the given stack, setting it up for use.
 *
 * @param stack A pointer to the Stack to be initialized.
 */
void stack_initialize(Stack *stack);
/**
 * @brief Creates a stack with the specified size.
 *
 * @param self Pointer to the stack object.
 * @param size The initial size of the stack.
 */
void stack_create(Stack *self, int size);

/**
 * @brief Checks if the stack is empty.
 *
 * @param self Pointer to the stack object.
 * @return true if the stack is empty, false otherwise.
 */
bool stack_isEmpty(const Stack *self);

/**
 * @brief Checks if the stack is full.
 *
 * @param self Pointer to the stack object.
 * @return true if the stack is full, false otherwise.
 */
bool stack_isFull(const Stack *self);

/**
 * @brief Pushes an element onto the stack.
 *
 * @param self Pointer to the stack object.
 * @param element The element to be pushed onto the stack.
 */
void stack_push(Stack *self, int element);

/**
 * @brief Pops an element from the stack.
 *
 * @param self Pointer to the stack object.
 * @return The element popped from the stack.
 */
int stack_pop(Stack *self);

/**
 * @brief Displays the elements of the stack.
 *
 * @param self Pointer to the stack object.
 */
void stack_display(const Stack *self);

/**
 * @brief Destroys the stack and frees any allocated memory.
 *
 * @param self Pointer to the stack object.
 */
void stack_destory(Stack *self);

/**
 * @brief Resizes the stack to the specified length.
 *
 * @param stack Pointer to the stack object.
 * @param resizeLenght The new size of the stack.
 * @return The new size of the stack.
 */
int stack_reSize(Stack *stack, int resizeLenght);

#pragma GCC diagnostic pop
#endif