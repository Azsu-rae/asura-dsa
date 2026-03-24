
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Data.h"

Node* node(Data data) {
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

void linkedList_free(Node** head) {
    if (*head) {
        linkedList_free(&((*head)->next));
    }

    free(*head);
    *head = NULL;
}

void insert_end(Node** head, Data data) {
    if (!*head) {
        *head = node(data);
    } else {
        Node* curr = *head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node(data);
    }
}

int linkedList_len(Node* head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

char* linkedList_to_str(Node* head) {
    int str_len = linkedList_len(head) * (4 + DATA_STR_LEN);
    char* to_str = malloc(str_len);
    while (head) {
        snprintf(to_str + strlen(to_str), str_len - strlen(to_str), "%s -> ", data_to_str(head->data));
        head = head->next;
    }
    snprintf(to_str + strlen(to_str), str_len - strlen(to_str), "NULL");

    return to_str;
}
