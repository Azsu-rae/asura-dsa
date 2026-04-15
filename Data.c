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

const DataVTable CHAR_VT = {.STR_LEN = 1, .create = char_create, .str = char_str};

Data char_create(void* char_val) { return (Data){.value = char_val, .vt = &CHAR_VT}; }
char* char_str(Data char_data) { return (char*)char_data.value; }
