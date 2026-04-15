#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

#include "Data.h"

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

Node* _node_create(Data data);
void LinkedList_free(Node** head);

void insert_end(Node** head, Data data);
void insert_start(Node** head, Data data);

bool LinkedList_remove(Node** head, int index);

char* LinkedList_to_str(Node* head);
int LinkedList_len(Node* head);

void LinkedList_test(int T[], int n);

#endif
