#include "Data.h"

#include <stdio.h>
#include <stdlib.h>

Data data(int x) { return (Data){.x = x}; }

char* data_to_str(Data data) {
    char* to_str = malloc(DATA_STR_LEN);
    snprintf(to_str, DATA_STR_LEN, "%d", data.x);
    return to_str;
}
