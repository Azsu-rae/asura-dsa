#ifndef DATA_H
#define DATA_H

#include "Type.h"

typedef struct Data {
    void* x;
    Type type;
    int STR_LEN;
    char* (*str)(struct Data);
    struct Data (*create)(void*, Type);
} Data;

#endif
