#include <stdlib.h>

#include "sorts.h"
#include "utils.h"

int main() {
    int *T, n;
    gen_random_array(&T, &n);
    display("Original Array: ", T, n);

    merge_sort(&T, n);
    display("Sorted Array: ", T, n);

    free(T);
    return 0;
}
