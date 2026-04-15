#include <stdio.h>
#include <stdlib.h>

#include "Simplex.h"

int main() {
    LP lp = LP_structured_input();
    char* buf = LP_to_str(lp);
    printf("%s\n", buf);
    free(buf);
    return 0;
}
