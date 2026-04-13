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

static inline char* Data_str(Data data) { return data.vt->str(data); }

Data int_create(void* int_val);
char* int_str(Data int_data);

#endif
