#ifndef ARRAYS_H
#define ARRAYS_H

#include <stddef.h>

void array_structured_input(int** T, int* n);
char* array_to_str(char* label, int* T, size_t n);

void** alloc_2d(size_t n, size_t m, size_t bytes);
void free_2d(void** mat, size_t n);

// sorting algorithms

// iterative
void selection_sort(int* T, int n);
void insertion_sort(int* T, int n);
void bubble_sort(int* T, int n);

// merge sort
void merge_sort(int* T, int n);
void _merge(int* T, int* T1, int n1, int* T2, int n2);
void _split(int* T, int n, int** T1, int n1, int** T2, int n2);

// quick_sort
void quick_sort(int* T, int n);
int _partition(int* T, int n);

#endif
