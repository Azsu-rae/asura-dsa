#include "Stack.h"

#include "Data.h"
#include "LinkedList.h"

Stack Stack_create() { return (Stack){.top = NULL}; }

void push(Stack stack, Data data) { insert_start(&stack.top, data); }

Data pop(Stack stack) {
    Data top = stack.top->data;

    return top;
}
