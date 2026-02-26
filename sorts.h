#ifndef SORTS_H
#define SORTS_H

#include <stdbool.h>

// sorting algorithms
void selection_sort(int* T, int n);
void insertion_sort(int* T, int n);
void bubble_sort(int* T, int n);

// merge sort
void merge_sort(int* T, int n);
void merge(int* T, int* T1, int n1, int* T2, int n2);
void split(int* T, int n, int** T1, int n1, int** T2, int n2);

// quick_sort
int partition(int* T, int n);
void quick_sort(int* T, int n);

#endif
