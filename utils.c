#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(char* label, int* T, int n) {
    printf("\n%s", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
}

void input(int** T, int* n) {
    scanf("%d", n);

    *T = malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++) {
        scanf("%d", *T + i);
    }
}

void gen_random_array(int** T, int* n) {
    srand(time(NULL));
    *n = rand() % 7 + 3;
    *T = malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++) {
        (*T)[i] = rand() % 10;
    }
}
