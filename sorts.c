#include "sorts.h"

#include <stdbool.h>
#include <stdlib.h>

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

void split(int* T, int n, int** T1, int n1, int** T2, int n2) {
    *T1 = malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        (*T1)[i] = T[i];
    }
    *T2 = malloc(sizeof(int) * (n - n2));
    for (int i = 0; i < n2; i++) {
        (*T2)[i] = T[i + n1];
    }
}

void merge_sort(int** T, int n) {
    if (n == 1) {
        return;
    }
    int mid = n / 2 + n % 2;
    int *T1, n1 = mid, *T2, n2 = n - mid;
    split(*T, n, &T1, n1, &T2, n2);

    merge_sort(&T1, n1);
    merge_sort(&T2, n2);

    *T = merge(T1, n1, T2, n2);
    free(T1);
    free(T2);
}

int* merge(int* T1, int n1, int* T2, int n2) {
    int* T = malloc(sizeof(int) * (n1 + n2));

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

    return T;
}

void quick_sort(int* T, int n) {
    int pivot = n / 2 + n % 2 - 1;
    for (int i = 0; i < n; i++) {
        if (T[i] > T[pivot]) {
            bool found_lt = false;
            for (int j = pivot + 1; j < n; j++) {
                if (T[j] < T[pivot]) {
                    int tmp = T[j];
                    T[j] = T[i];
                    T[i] = tmp;
                    found_lt = true;
                    break;
                }
            }

            if (!found_lt) {
                int tmp = T[pivot];
                T[pivot] = T[i];
                T[i] = tmp;
            }
        }
    }
}
