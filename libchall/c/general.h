#ifndef LIBCHALL_GENERAL_H
#define LIBCHALL_GENERAL_H

#include <stdio.h>
#include "ds/vector.h"


/**
 * split a string and store tokens in a vector
 */
void str_split(Vector *vp, const char *str, const char *delim) {
    /* including null terminator character */
    char *tmp = (char*) calloc(sizeof(char), strlen(str) + 1);
    if (tmp == NULL)
        goto do_nothing;

    strcpy(tmp, str);
    char *token;

    token = strtok(tmp, delim);
    while (token != NULL) {
        vec_append(vp, token, strlen(token));
        token = strtok(NULL, delim);
    }
do_nothing:
    token = NULL;
}


/**
 * partition function for quicksort
 */
static int partition(Vector *vp, size_t lower, size_t upper) {
    int i = (lower - 1);
    const int pivot = *(int*)vec_get(vp, upper);

    for (int j = lower; j < (int)upper; j++) {
        if (*(int*)vec_get(vp, j) <= pivot) {
            i++;
            vec_swap(vp, i, j);
        }
    }

    vec_swap(vp, i + 1, upper);
    return (i < 0) ? 1 : (i + 1);
}


/**
 * sorting vector with quicksort 
 */
void vec_sort(Vector *vp, size_t lower, size_t upper) {
    if (upper > lower) {
        int partitionIndex = partition(vp, lower, upper);
        vec_sort(vp, lower, partitionIndex - 1);
        vec_sort(vp, partitionIndex + 1, upper);
    }
}


/**
 * convert an string of numbers to an int
 */
int str_to_int(const char *str) {
    int tmp = 0;

    if (sscanf(str, "%d", &tmp) == 1) {
        sscanf(str, "%d", &tmp);
    } else
        return 0;

    return tmp;
}


#endif
