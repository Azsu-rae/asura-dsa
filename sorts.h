#ifndef SORTS_H
#define SORTS_H

// sorting algorithms
void selection_sort(int* T, int n);
void insertion_sort(int* T, int n);
void bubble_sort(int* T, int n);

// merge sort
void merge_sort(int** T, int n);
int* merge(int* T1, int n1, int* T2, int n2);
void split(int* T, int n, int** T1, int n1, int** T2, int n2);

#endif
