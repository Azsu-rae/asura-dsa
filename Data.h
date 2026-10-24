#ifndef DATA_H
#define DATA_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef enum {
    SIZE_T,
    UBYTE,
    INT,
    DOUBLE,
} DType;

void* DType_index(void* data, DType dtype, size_t i);
void DType_print(void* data, DType dtype);

size_t DType_sizeof(DType dtype);
void DType_desc(DType dtype);

typedef struct Data Data;

typedef struct DataVTable {
    size_t STR_LEN;
    char* (*str)(Data);
    Data (*create)(void*);
} DataVTable;

struct Data {
    void* value;
    const DataVTable* vt;
};

static inline char* Data_str(Data data) { return data.vt->str(data); }
static inline size_t Data_STR_LEN(Data data) { return data.vt->STR_LEN; }

Data int_create(void* int_val);
char* int_str(Data int_data);

Data char_create(void* char_val);
char* char_str(Data char_data);

#endif
