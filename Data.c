#include "Data.h"

#include <stdio.h>
#include <stdlib.h>

const DataVTable INT_VT = {.STR_LEN = 20, .create = int_create, .str = int_str};


void* DType_index(void* data, DType dtype, size_t i) {
    switch(dtype) {
        case (SIZE_T):
            return ((size_t*) data) + i;
        case (INT):
            return ((int*) data) + i;
        case (UBYTE):
            return ((uint8_t*) data) + i;
        case (DOUBLE):
            return ((double*) data) + i;
    }
}


void DType_desc(DType dtype) {
    switch(dtype) {
        case (SIZE_T):
            printf("SIZE_T");
            break;
        case (INT):
            printf("INT");
            break;
        case (UBYTE):
            printf("UBYTE");
            break;
        case (DOUBLE):
            printf("DOUBLE");
            break;
    }
}

void DType_print(void* data, DType dtype) {
    switch(dtype) {
        case (SIZE_T):
            printf("%lu", *((size_t*)data));
            break;
        case (INT):
            printf("%d", *((int*)data));
            break;
        case (UBYTE):
            printf("%" PRId8, *((int*)data));
            break;
        case (DOUBLE):
            printf("%f", *((double*)data));
            break;
    }
}


size_t DType_sizeof(DType dtype) {
    switch(dtype) {
        case (SIZE_T):
            return sizeof(size_t);
        case (INT):
            return sizeof(int);
        case (UBYTE):
            return sizeof(int);
        case (DOUBLE):
            return sizeof(double);
    }
}

Data int_create(void* int_val) { return (Data){.value = int_val, .vt = &INT_VT}; }

char* int_str(Data int_data) {
    char* to_str = malloc(int_data.vt->STR_LEN);
    snprintf(to_str, int_data.vt->STR_LEN, "%d", *((int*)int_data.value));
    return to_str;
}

const DataVTable CHAR_VT = {.STR_LEN = 1, .create = char_create, .str = char_str};

Data char_create(void* char_val) { return (Data){.value = char_val, .vt = &CHAR_VT}; }
char* char_str(Data char_data) { return (char*)char_data.value; }
