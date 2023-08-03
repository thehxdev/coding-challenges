#include <stdio.h>
#include <ds/vector.h>
#include <general.h>
#include "d1.h"

#define INPUT_FILE "./input.txt"

int challenge1(Vector *esv);
int challenge2(Vector *esv);

int main(void) {
    Vector *elves_sum = calc_elves_sum(INPUT_FILE);

    int result1 = challenge1(elves_sum);
    int result2 = challenge2(elves_sum);
    printf("Challenge 1: %d\n", result1);
    printf("Challenge 2: %d\n", result2);

    vec_free(elves_sum);
    return 0;
}


int challenge1(Vector *esv) {
    int max_elf = vec_max(esv);
    return max_elf;
}


int challenge2(Vector *esv) {
    vec_sort(esv, 0, esv->length - 1);
    int max_three_elf = 0;

    for (uint32_t i = 1; i < esv->length; i++) {
        if (i == 4)
            break;
        max_three_elf += *(int*)vec_get(esv, esv->length - i);
    }

    return max_three_elf;
}

