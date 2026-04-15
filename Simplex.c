#include "Simplex.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrays.h"

// clang-format off
LP LP_allocate(int n, int m) {
    return (LP) {
        .n = n,
        .m = m,
        .c = malloc(sizeof(float) * n),
        .A = (float**) alloc_2d(m, n, sizeof(float)),
        .b = malloc(sizeof(float) * m),
        .canonical = malloc(sizeof(bool) * m),
    };
}

// clang-format on
void LP_free(LP lp) {
    free(lp.c);
    free_2d((void**)lp.A, lp.n);
    free(lp.b);
    free(lp.canonical);
}

LP LP_structured_input() {
    int n, m;
    printf("\nEnter n (variables) and m (constraints): ");
    scanf("%d %d", &n, &m);
    printf("\nn = %d\nm = %d\n\n", n, m);

    printf("objetive function + constraints:\n\n");
    LP lp = LP_allocate(n, m);
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 && j == n + 1) {
                continue;
            }

            float tmp;
            scanf("%f", &tmp);
            if (i == 0 && j == 0) {
                lp.maximization = (tmp == 1.0);
            } else if (i == 0) {
                lp.c[j - 1] = tmp;
            } else if (j == n) {
                lp.canonical[i - 1] = (tmp == 1.0);
            } else if (j == n + 1) {
                lp.b[i - 1] = tmp;
            } else {
                lp.A[i - 1][j] = tmp;
            }
        }
    }

    return lp;
}

// clang-format off
char* LP_to_str(LP lp) {
    size_t len = (lp.m + 1) * lp.n * 30;
    char* buf = calloc(len, sizeof(char));
    for (size_t j = 0; j < lp.m + 1; j++) {
        if (j == 0) {
            snprintf(buf, len, "%s =", lp.maximization ? "Max(Z)" : "Min(Z)");
        } for (size_t i = 0, first = 1; i < lp.n; i++, first = 0) {
            char* operator;
            float coef;
            if (first) {
                operator = "";
                coef = lp.c[i];
            } else {
                operator = lp.c[i] < 0 ? " -" : " +";
                coef = fabsf(lp.c[i]);
            } snprintf(buf + strlen(buf), len + strlen(buf), "%s %.2fx_%zu", operator, coef, i+1);
        } if (j > 0) {
            snprintf(buf + strlen(buf), len + strlen(buf), " %s %.2f", lp.canonical[j-1] ? "<=" : ">=", lp.b[j-1]);
        } snprintf(buf + strlen(buf), len + strlen(buf), "\n");
    }

    return buf;
}
