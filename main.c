#include <stdio.h>
#include <stdlib.h>

#include "Data.h"
#include "LinkedList.h"

int main() {
    int T[] = {1, 2, 3, 4, 5}, n = 5;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        insert_end(&head, int_create(T + i));
    }

    //    printf("%s ", head->data.vt->str(head->next->data));

    char* buff = LinkedList_to_str(head);
    printf("%s\n", buff);
    free(buff);

    LinkedList_free(&head);
    return 0;
}
