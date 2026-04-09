#include "Type.h"

int size(Type type) {
    if (type == INT) {
        return sizeof(int);
    }
    return -1;
}
