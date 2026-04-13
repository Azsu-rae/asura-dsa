
#include "LinkedList.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Data.h"

Node* Node_create(Data data) {
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

void LinkedList_free(Node** head) {
    Node* curr = *head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    *head = NULL;
}

void insert_end(Node** head, Data data) {
    if (!*head) {
        *head = Node_create(data);
    } else {
        Node* curr = *head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = Node_create(data);
    }
}

void insert_start(Node** head, Data data) {
    Node* old_head = *head;
    *head = Node_create(data);
    (*head)->next = old_head;
}

int LinkedList_len(Node* head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

char* LinkedList_to_str(Node* head) {
    if (!head) {
        return "NULL";
    }

    int str_len = LinkedList_len(head) * (4 + head->data.vt->STR_LEN);
    char* to_str = malloc(str_len);
    while (head) {
        snprintf(to_str + strlen(to_str), str_len - strlen(to_str), "%s -> ", Data_str(head->data));
        head = head->next;
    }
    snprintf(to_str + strlen(to_str), str_len - strlen(to_str), "NULL");

    return to_str;
}

bool LinkedList_remove(Node** head, int index) {
    int i = 0;
    Node *curr = *head, *prev = *head;
    while (i < index && curr) {
        i++;
        prev = curr;
        curr = curr->next;
    }

    if (index == 0 && curr) {
        free(*head);
        *head = curr->next;
        return true;
    } else if (curr) {
        prev->next = curr->next;
        free(curr);
        return true;
    } else {
        return false;
    }
}
