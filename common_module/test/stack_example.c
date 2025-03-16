#include "collections.h"

int main()
{
    Stack stack;
    stack_initialize(&stack);
    stack.stack_create(&stack, 5);

    stack.stack_push(&stack, 1);
    stack.stack_push(&stack, 2);
    stack.stack_push(&stack, 3);
    stack.stack_push(&stack, 4);
    stack.stack_push(&stack, 5);
    stack.stack_push(&stack, 6);
    stack.stack_push(&stack, 7);
    // stack.pop(&stack);
    // stack.pop(&stack);
    // display stack element
    stack.stack_display(&stack);
    stack.stack_destory(&stack);

    return 0;
}