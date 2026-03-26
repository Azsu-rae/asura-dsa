#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "LinkedList.h"

typedef struct {
    Node* top;
} Stack;

void push(Stack stack, Data data);
Data pop(Stack stack);

#endif
