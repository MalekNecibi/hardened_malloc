#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>

#include "test_util.h"

OPTNONE int main(void) {
    sleep(1);

    char *p = malloc(128);
    if (!p) {
        return 1;
    }
    // free(p);

    for (size_t i = 0; i < 30 * 1000 * 1000; i++) {
        free(malloc(128));
        // if (0 == (i % (1000*1000))) {
        //     printf("i = %zu\n", i);
        // }
    }

    free(p);
    return 0;
}
