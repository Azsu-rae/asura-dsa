#include <stdio.h>
#include <stdlib.h>

#include "Data.h"
#include "LinkedList.h"
#include "Type.h"

Data _create(void* x, Type type) { return (Data){.x = malloc(sizeof(int))}; }

char* _str(Data data) {
    char* to_str = malloc(data.STR_LEN);
    snprintf(to_str, data.STR_LEN, "%d", *(int*)data.x);
    return to_str;
}

int main() {
    Data data = {
        .x = NULL,
        .type = INT,
        .STR_LEN = 20,
        .create = _create,
        .str = _str,
    };

    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        insert_start(&head, _create(tmp));
    }

    char* buff = LinkedList_to_str(head);
    printf("%s\n", buff);
    free(buff);

    LinkedList_free(&head);
    return 0;
}
