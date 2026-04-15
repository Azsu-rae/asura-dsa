#include "utils.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Data.h"
#include "LinkedList.h"
#include "Stack.h"

void gen_random_array(int** T, int size, int max_val) {
    srand(time(NULL));
    *T = malloc(sizeof(int) * (size));
    for (int i = 0; i < size; i++) {
        (*T)[i] = rand() % max_val;
    }
}

double avg(int size, void (*sort)(int*, int), int** arr) {
    double total = 0;
    for (int i = 0; i < 30; i++) {
        double cpu_time_used;
        clock_t start, end;
        start = clock();
        sort(arr[(size / 100) - 1], size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        total += cpu_time_used;
    }
    double avg_cpu_time_used = total / 30;
    return avg_cpu_time_used;
}

void benchmark() {
    void (*sort_algo[])(int*, int) = {selection_sort, bubble_sort, insertion_sort, merge_sort, quick_sort};

    double cpu_time[5][4];
    int* arr[4] = {};
    for (int s = 0; s < 5; s++) {
        for (int size = 100; size <= 10000; size *= 10) {
            int index = ((int)size / 100) - 1;
            if (!arr[index]) {
                gen_random_array(&arr[index], size, size * 10);
            }
            cpu_time[s][index] = avg(size, sort_algo[s], arr);
        }
    }

    printf(
        "algorithm\\array_size    100         1000         10000         "
        "100000\n");
    printf("                                               \n");
    printf("selection_sort          %f    %f     %f    %f\n", cpu_time[0][0], cpu_time[0][1], cpu_time[0][2],
           cpu_time[0][3]);
    printf("bubble_sort             %f    %f     %f    %f\n", cpu_time[1][0], cpu_time[1][1], cpu_time[1][2],
           cpu_time[1][3]);
    printf("insertion_sort          %f    %f     %f    %f\n", cpu_time[2][0], cpu_time[2][1], cpu_time[2][2],
           cpu_time[2][3]);
    printf("merge_sort              %f    %f     %f    %f\n", cpu_time[3][0], cpu_time[3][1], cpu_time[3][2],
           cpu_time[3][3]);
    printf("quick_sort              %f    %f     %f    %f\n", cpu_time[4][0], cpu_time[4][1], cpu_time[4][2],
           cpu_time[4][3]);
    return;
}

void Stack_test(int T[], int n) {
    Stack stack = (Stack){.top = NULL};
    for (int i = 0; i < n; i++) {
        push(&stack, int_create(T + i));
    }

    while (!is_empty(stack)) {
        printf("%s\n", Data_str(pop(&stack)));
    }

    Stack_free(&stack);
}
