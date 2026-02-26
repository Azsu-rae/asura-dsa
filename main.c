#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"
#include "utils.h"

#define debug false

void placeholder() {
    int *T, n;
    if (debug) {
        T = (int[]){2, 5, 2, 9, 0, 8, 5, 1, 9};
        n = 9;
    } else {
        n = 100000;
        gen_random_array(&T, n, n);
    }
    //    display("Original Array: ", T, n);

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    quick_sort(T, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time: %f seconds\n", cpu_time_used);
    //    display("Sorted Array: ", T, n);

    if (!debug) {
        free(T);
    }
    printf("\n");
}

int main() {
    benchmark();
    return 0;
}
