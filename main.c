#include <stdio.h>
#include <stdlib.h>

#include "Data.h"
#include "LinkedList.h"
#include "Stack.h"

void stack(int T[], int n) {
    Stack stack = (Stack){.top = NULL};
    for (int i = 0; i < n; i++) {
        push(&stack, int_create(T + i));
    }

    while (!is_empty(stack)) {
        printf("%s\n", Data_str(pop(&stack)));
    }

    Stack_free(&stack);
}

void linked_list(int T[], int n) {
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        insert_end(&head, int_create(T + i));
    }

    char* buf = LinkedList_to_str(head);
    printf("%s\n", buf);
    free(buf);

    LinkedList_free(&head);
}

int main() {
    int T[] = {1, 2, 3, 4, 5}, n = 5;
    stack(T, n);
    return 0;
}
