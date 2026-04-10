#include "Data.h"

#include <stdio.h>
#include <stdlib.h>

const DataVTable INT_VT = {.STR_LEN = 20, .create = int_create, .str = int_str};

Data int_create(void* int_val) { return (Data){.value = int_val, .vt = &INT_VT}; }

char* int_str(Data int_data) {
    char* to_str = malloc(int_data.vt->STR_LEN);
    snprintf(to_str, int_data.vt->STR_LEN, "%d", *((int*)int_data.value));
    return to_str;
}
