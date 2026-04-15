#ifndef DATA_H
#define DATA_H

#include <stddef.h>

typedef struct Data Data;

typedef struct DataVTable {
    size_t STR_LEN;
    char* (*str)(Data);
    Data (*create)(void*);
} DataVTable;

typedef struct Data {
    void* value;
    const DataVTable* vt;
} Data;

static inline char* Data_str(Data data) { return data.vt->str(data); }
static inline size_t Data_STR_LEN(Data data) { return data.vt->STR_LEN; }

Data int_create(void* int_val);
char* int_str(Data int_data);

Data char_create(void* char_val);
char* char_str(Data char_data);

#endif
