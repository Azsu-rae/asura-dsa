#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Data.h"

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

Node* node(Data data);
void linkedList_free(Node** head);

void insert_end(Node** head, Data data);
void insert_start(Node** head);

int linkedList_len(Node* head);
char* linkedList_to_str(Node* head);

#endif
