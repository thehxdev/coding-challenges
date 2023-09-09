#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef struct __list {
    void **vals;
    size_t len;
    size_t cap;
} List;


int gen_rand(int lower, int upper);

List *list_new(const size_t cap);

void list_free(List *lp);

int list_append(List *lp, void *val, size_t bytes);

List *list_breakdown_rand(List *lp, const size_t max_len);

List *list_merge_inner(List *lp);

#endif // ARRAY_H
