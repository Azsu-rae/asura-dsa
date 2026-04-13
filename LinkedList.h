#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

#include "Data.h"

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

Node* node_create(Data data);

void insert_end(Node** head, Data data);
void insert_start(Node** head, Data data);

int LinkedList_len(Node* head);
void LinkedList_free(Node** head);
char* LinkedList_to_str(Node* head);
bool LinkedList_remove(Node** head, int index);

#endif
