#include "Stack.h"

#include <stdbool.h>
#include <stdio.h>

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

void Stack_test(int T[], int n) {
    Stack stack = (Stack){.top = NULL};
    for (int i = 0; i < n; i++) {
        push(&stack, int_create(T + i));
    }

    while (!is_empty(stack)) {
        printf("%s\n", Data_str(pop(&stack)));
    }

    Stack_free(&stack);
}
