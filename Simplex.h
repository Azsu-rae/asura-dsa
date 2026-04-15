#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <stdbool.h>

typedef struct LP {
    int n;  // number of variables
    int m;  // number of constraints

    bool maximization;  // maximize the objective
    float* c;           // objective coefficients

    bool* canonical;  // constraints relations: whether < or >
    float** A;        // constraints coefficients
    float* b;         // right-hand side vector

} LP;

LP LP_allocate(int n, int m);
void LP_free(LP lp);

LP LP_structured_input();

void simplex();

#endif
