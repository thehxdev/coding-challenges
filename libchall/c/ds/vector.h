#ifndef LIBCHALL_VECTOR_H
#define LIBCHALL_VECTOR_H


#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

#define DEFAULT_CAP 20


struct __vector {
    size_t capacity;
    size_t length;
    void **elems;
};
typedef struct __vector Vector;



static bool check_idx(size_t size, size_t idx) {
    return (idx < size) ? true : false;
}


/**
 * Create a new vector and return a pointer to it.
 * Returns NULL if failed.
 */
Vector *vec_new(void) {
    /* new vector */
    Vector *nv = (Vector*) malloc(sizeof(Vector));
    if (nv == NULL)
        return NULL;

    nv->length = 0;
    nv->capacity = DEFAULT_CAP;
    nv->elems = (void**) calloc(sizeof(void*), DEFAULT_CAP);

    return nv;
}


/**
 * Free and delete a vector
 */
void vec_free(Vector *vp) {
    if (vp->elems != NULL) {
        for (uint32_t i = 0; i < vp->length; i++) {
            if (vp->elems[i])
                free(vp->elems[i]);
        }
        free(vp->elems);
    }

    if (vp)
        free(vp);
}


/**
 * Append a new element to vector
 */
int vec_append(Vector *vp, void *val, size_t bytes) {
    if (vp->length % vp->capacity == 0) {
        size_t new_size = (vp->length + vp->capacity) * sizeof(void*);
        vp->elems = (void**) realloc(vp->elems, new_size);
    }
    if (vp->elems == NULL)
        return 1;

    vp->elems[vp->length] = (void*) malloc(bytes);
    if (vp->elems[vp->length] == NULL)
        return 1;

    memcpy(vp->elems[vp->length], val, bytes);
    vp->length += 1;
    return 0;
}


void *vec_get(Vector *vp, size_t idx) {
    if (!check_idx(vp->length, idx))
        return NULL;

    return vp->elems[idx];
} 


void vec_swap(Vector *vp, size_t idx1, size_t idx2) {
    if (check_idx(vp->length, idx1) && check_idx(vp->length, idx2)) {
        void *tmp = vec_get(vp, idx1);
        vp->elems[idx1] = vp->elems[idx2];
        vp->elems[idx2] = tmp;
    }
}


void vec_set(Vector *vp, size_t idx, void *val, size_t size) {
    if (check_idx(vp->length, idx)) {
        free(vec_get(vp, idx));
        vp->elems[idx] = (void*) malloc(size);
        memcpy(vp->elems[idx], val, size);
    }
}


void *vec_pop(Vector *vp) {
    if (vp->length == 0)
        return NULL;

    void *last_element = vec_get(vp, vp->length - 1);

    vp->elems[vp->length] = NULL;
    vp->elems = (void**) realloc(vp->elems, vp->length - 1);

    vp->length -= 1;
    return last_element;
}


void vec_clean(Vector *vp) {
    if (vp->elems) {
        for (uint32_t i = 0; i < vp->length; i += 1) {
            if (vp->elems[i])
                free(vp->elems[i]);
        }
        free(vp->elems);
    }

    vp->elems = (void**) calloc(sizeof(void*), DEFAULT_CAP);
    vp->capacity = DEFAULT_CAP;
    vp->length = 0;
}


#endif
