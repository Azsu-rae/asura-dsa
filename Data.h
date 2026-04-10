#ifndef DATA_H
#define DATA_H

typedef struct Data Data;

typedef struct DataVTable {
    int STR_LEN;
    char* (*str)(Data);
    Data (*create)(void*);
} DataVTable;

typedef struct Data {
    void* value;
    const DataVTable* vt;
} Data;

Data int_create(void* int_val);
char* int_str(Data int_data);

#endif
