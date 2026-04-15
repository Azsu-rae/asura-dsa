#include "arrays.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array_structured_input(int** T, int* n) {
    scanf("%d", n);
    *T = malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++) {
        scanf("%d", *T + i);
    }
}

char* array_to_str(char* label, int* T, size_t n) {
    printf("\n%s", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
}

void** alloc_2d(size_t n, size_t m, size_t bytes) {
    void** mat = malloc(bytes * n);
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(bytes * m);
    }

    return mat;
}

void free_2d(void** mat, size_t n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

void selection_sort(int* T, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (T[j] < T[min]) {
                min = j;
            }
        }
        int tmp = T[i];
        T[i] = T[min];
        T[min] = tmp;
    }
}

void insertion_sort(int* T, int n) {
    for (int i = 1; i < n; i++) {
        int tmp = T[i];
        int j = i - 1;
        while (j >= 0 && T[j] > tmp) {
            T[j + 1] = T[j];
            j = j - 1;
            T[j + 1] = tmp;
        }
    }
}

void bubble_sort(int* T, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                int tmp = T[j + 1];
                T[j + 1] = T[j];
                T[j] = tmp;
            }
        }
    }
}

void _split(int* T, int n, int** T1, int n1, int** T2, int n2) {
    *T1 = malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        (*T1)[i] = T[i];
    }
    *T2 = malloc(sizeof(int) * n2);
    for (int i = 0; i < n2; i++) {
        (*T2)[i] = T[i + (n - n2)];
    }
}

void merge_sort(int* T, int n) {
    if (n <= 1) {
        return;
    }
    int mid = n / 2 + n % 2;
    int *T1, n1 = mid, *T2, n2 = n - mid;
    _split(T, n, &T1, n1, &T2, n2);

    merge_sort(T1, n1);
    merge_sort(T2, n2);

    _merge(T, T1, n1, T2, n2);
    free(T1);
    free(T2);
}

void _merge(int* T, int* T1, int n1, int* T2, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        T[k++] = T1[i] < T2[j] ? T1[i++] : T2[j++];
    }

    while (i < n1) {
        T[k++] = T1[i++];
    }

    while (j < n2) {
        T[k++] = T2[j++];
    }
}

int _partition(int* T, int n) {
    srand(time(NULL));
    int pivot = rand() % n;
    int bgt = -1;
    for (int i = 0; i < n; i++) {
        if (T[i] <= T[pivot]) {
            int tmp = T[++bgt];
            T[bgt] = T[i];
            T[i] = tmp;
            if (bgt == pivot) {
                pivot = i;
            }
            if (i == pivot) {
                pivot = bgt;
            }
        }
    }

    if (pivot > bgt) {
        bgt++;
    }
    int tmp = T[bgt];
    T[bgt] = T[pivot];
    T[pivot] = tmp;
    pivot = bgt;

    return pivot;
}

void quick_sort(int* T, int n) {
    if (n <= 1) {
        return;
    }
    int pivot = _partition(T, n);
    int n1 = pivot, n2 = n - pivot - 1;
    int *T1 = T, *T2 = T + pivot + 1;
    quick_sort(T1, n1);
    quick_sort(T2, n2);
    return;
}
