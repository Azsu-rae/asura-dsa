#include <stdio.h>
#include <stdlib.h>

#include "Data.h"
#include "LinkedList.h"

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        insert_end(&head, Data_create(tmp));
    }

    char* buff = LinkedList_to_str(head);
    printf("%s\n", buff);
    free(buff);

    LinkedList_free(&head);
    return 0;
}
