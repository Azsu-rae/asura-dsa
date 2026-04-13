#include "Stack.h"

#include <stdbool.h>

#include "Data.h"
#include "LinkedList.h"

Stack Stack_create() { return (Stack){.top = NULL}; }

void push(Stack* stack, Data data) { insert_start(&stack->top, data); }

Data pop(Stack* stack) {
    Data top = stack->top->data;
    LinkedList_remove(&stack->top, 0);
    return top;
}

bool is_empty(Stack stack) { return stack.top == NULL; }

void Stack_free(Stack* stack) { LinkedList_free(&stack->top); }
