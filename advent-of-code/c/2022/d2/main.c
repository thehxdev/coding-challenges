#include <stdio.h>
#include <stdint.h>

uint64_t power(uint64_t num, uint64_t p);


int main(void) {
    uint64_t x = power(2, 64);
    printf("%lu\n", x - 1);
    return 0;
}


uint64_t power(uint64_t num, uint64_t p) {
    uint64_t y = num;
    for (uint64_t i = 0; i < p; i++) {
        y *= num;
    }
    return y;
}
