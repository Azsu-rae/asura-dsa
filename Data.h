#ifndef DATA_H
#define DATA_H

#define DATA_STR_LEN 20

typedef struct {
    int x;
} Data;

Data Data_create(int x);

char* Data_to_str(Data data);

#endif
