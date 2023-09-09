#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "array.h"

#define check_then_free(p) if ((p)) free((p))

// generate a random number between @lower and @upper (inclusive)
int gen_rand(int lower, int upper) {
    int rand_num = ((rand() % (upper - lower + 1)) + lower);
    return rand_num;
}


// create a new dynamic array
List *list_new(const size_t cap) {
    List *l = (List*) malloc(sizeof(List));
    if (l == NULL)
        return NULL;

    l->vals = (void**) calloc(sizeof(void*), cap);
    if (l->vals == NULL) {
        free(l);
        return NULL;
    }

    l->cap = cap;
    l->len = 0;

    return l;
}


// free a dynamic array
void list_free(List *lp) {
    if (lp) {
        for (size_t i = 0; i < lp->len; i++)
            check_then_free(lp->vals[i]);
        check_then_free(lp->vals);
        free(lp);
    }
}


// append to array
int list_append(List *lp, void *val, size_t bytes) {
    if (lp == NULL)
        return 1;

    // if length of array is divisible by it's capacity,
    // grow it's size by it's capacity
    if (lp->len % lp->cap == 0) {
        size_t new_size = sizeof(void*) * (lp->len + lp->cap);
        lp->vals = (void**) realloc(lp->vals, new_size);
        if (lp->vals == NULL) {
            list_free(lp);
            return 1;
        }
    }

    lp->vals[lp->len] = (void*) malloc(bytes);
    memmove(lp->vals[lp->len], val, bytes);
    lp->len += 1;

    return 0;
}


// break an array into smaller arrays with maximum length of @max_len
// while each chunk has a random lenght
List *list_breakdown_rand(List *lp, const size_t max_len) {
    if (lp->len <= max_len)
        return lp;

    size_t right = 0, left = 0; // right and left pointer
    List *super_list = list_new(20); // super list to store smaller lists
    List *tmp = NULL; // tmp list to create small lists
    while (right < lp->len) {
        left = (size_t) gen_rand(right, right + max_len - 1);
        if (left >= lp->len)
            left = lp->len - 1;
        else if (left == right)
            continue; // don't create empty lists

        tmp = list_new(max_len + 1);
        for (size_t i = right; i <= left; i++)
            list_append(tmp, (int*)lp->vals[i], sizeof(int));

        // Just store the `tmp` list as pointer and not all of it
        list_append(super_list, (List*)tmp, sizeof(List));

        // free tmp list but NOT it's data
        // because we need it in super list
        free(tmp);
        right = left + 1;
    }

    return super_list;
}

// TODO
List *list_merge_inner(List *lp);
