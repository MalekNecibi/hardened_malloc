#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_util.h"

#define ABC_MALEK 42
#define AREA(l, b) ((l) * (b))


OPTNONE int main(void) {
    void *p = NULL;
    size_t size = 256 * 1024;
    
    for (unsigned i = 0; i < 20; i++) {
        p = realloc(p, size);
        if (!p) {
            return 1;
        }
        memset(p, 'a', size);
        size = size * 3 / 2;
    }
    size_t** last = (size_t**) malloc(sizeof(size_t*));

    for (size_t i = 1; i <= 512 * 1024 * 1024; i = (i*2)) {
        *last = (size_t*) malloc(i);
        if (!*last) {
            printf("ERROR: malloc failed at %zu\n", i);
            return 1;
        }
        memset(*last, i % 26 + 'a', i);
        printf("%zu bytes\n", i);
    }
    printf("done!\n");
    
    return 0;
}
