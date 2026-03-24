#ifndef DATA_H
#define DATA_H

#define DATA_STR_LEN 20

typedef struct {
    int x;
} Data;

Data data(int x);

char* data_to_str(Data data);

#endif
