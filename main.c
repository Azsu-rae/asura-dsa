#include <stdbool.h>
#include <stdlib.h>

#include "utils.h"

int main() {
    int *T, n;
    input(&T, &n);
    linked_list(T, n);
    free(T);
    return 0;
}
