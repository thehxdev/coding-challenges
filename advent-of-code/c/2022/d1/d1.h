#ifndef AOC_2022_D1_H
#define AOC_2022_D1_H

#include <general.h>
#include <stdio.h>
#include <ds/vector.h>

Vector *calc_elves_sum(const char *input_file) {
    Vector *esv = vec_new(); /* elves sum vector */
    char buff[128];
    int num = 0, sum =0;

    FILE *fp = fopen(input_file, "r");
    if (fp == NULL)
        return NULL;

    while (fgets(buff, 128, fp)) {
        if (buff[0] == '\n') {
            vec_append(esv, &sum, sizeof(sum));
            sum = 0;
            continue;
        }
        num = str_to_int(buff);
        sum += num;
    }

    fclose(fp);
    return esv;
}


int vec_max(Vector *vp) {
    int max_num = *(int*)vec_get(vp, 0);

    for (uint32_t i = 0; i < vp->length; i++) {
        if (*(int*)vec_get(vp, i) > max_num)
            max_num = *(int*)vec_get(vp, i);
    }

    return max_num;
}

#endif
