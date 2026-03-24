#include <stdio.h>
#include <stdlib.h>

#include "Data.h"
#include "LinkedList.h"

void LinkedListTest() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        insert_end(&head, data(tmp));
    }

    char* buff = linkedList_to_str(head);
    printf("%s\n", buff);

    linkedList_free(&head);
    free(buff);
}

int main() {
    LinkedListTest();
    return 0;
}
