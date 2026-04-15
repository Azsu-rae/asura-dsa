#include "Simplex.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

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
                lp.maximization = (bool)tmp;
            } else if (i == 0) {
                lp.c[j - 1] = tmp;
            } else if (j == n) {
                lp.canonical[i - 1] = (bool)tmp;
            } else if (j == n + 1) {
                lp.b[i - 1] = tmp;
            } else {
                lp.A[i - 1][j] = tmp;
            }
        }
    }

    return lp;
}

char* LP_to_str(LP lp) {
    char* buf = malloc(sizeof(char) * (lp.m + 1) * lp.n * 30);
    for (int i = 0; i < m + 1; i++) {
        bool first = true;
        for (int j = 0; j < n + 2; j++) {
            float curr = constraints[i][j];
            if (i == 0 && j == 0) {
                printf("\n%s =", curr == 0 ? "Min(Z)" : "Max(Z)");
                continue;
            }
            if (i == 0) {
                if (j == n + 1) {
                    continue;
                }
                printf("%s %.2fx_%d", curr < 0 ? " -" : first ? "" : " +", fabsf(curr), j);
            } else if (j < n) {
                printf("%s %.2fx_%d", curr < 0 ? " -" : first ? "" : " +", fabsf(curr), j + 1);
            } else if (j == n) {
                printf(" %c= ", curr == 0 ? '<' : '>');
            } else {
                printf("%.2f", curr);
            }
            first = false;
        }
        printf("\n");
    }
    printf("\n");
}
