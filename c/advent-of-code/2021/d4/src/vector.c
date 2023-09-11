#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define VEC_DEFAULT_CAP 20
#define check_then_free(p) if ((p)) free((p))

Vector *vec_new(const size_t cap) {
    size_t capacity = (cap == 0) ? VEC_DEFAULT_CAP : cap;
    Vector *v = (Vector*) malloc(sizeof(Vector));
    if (v == NULL)
        return NULL;

    v->data = (int*) calloc(sizeof(int), capacity);
    if (v->data == NULL) {
        free(v);
        return NULL;
    }

    v->len  = 0;
    v->cap  = capacity;

    return v;
}


void vec_free(Vector *vp) {
    if (vp) {
        check_then_free(vp->data);
        free(vp);
    }
}


void vec_append(Vector *vp, int val) {
    if (vp == NULL)
        return;

    if (vp->len % vp->cap == 0) {
        size_t new_size = sizeof(int) * (vp->len + vp->cap);
        vp->data = (int*) realloc(vp->data, new_size);
        if (vp->data == NULL) {
            vec_free(vp);
            return;
        }
    }

    vp->data[vp->len] = val;
    vp->len += 1;
}


void vec_print(Vector *vp, const char *name) {
    if (vp) {
        printf("%s = { ", name);
        for (size_t i = 0; i < vp->len; i++)
            printf("%d ", vp->data[i]);
        printf("}\n");
    }
}
