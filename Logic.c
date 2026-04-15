
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Data.h"
#include "Stack.h"

// clang-format off
bool is_operator(char curr) {
    return curr == 'A'
        || curr == 'O'
        || curr == '~'
        || curr == '-'
        || curr == '<'
        || curr == 'X'
        || curr == '('
        || curr == ')';
}

// clang-format on
bool is_lowercase(int curr) { return curr >= 97 && curr <= 122; }  // a = 97 z = 122

void logic() {
    char formula[1000];
    fgets(formula, sizeof(formula), stdin);

    Stack operands = Stack_create();
    for (int i = 0; i < strlen(formula); i++) {
        char curr = formula[i];
        if (is_lowercase(curr)) {
            push(&operands, char_create(formula + i));
            continue;
        }

        if (!is_operator(curr)) {
            continue;
        }
    }

    Stack_free(&operands);
}
