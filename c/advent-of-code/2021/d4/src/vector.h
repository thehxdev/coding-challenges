#ifndef AOC_2021_D4_VECTOR_H
#define AOC_2021_D4_VECTOR_H

#include <stddef.h>

typedef struct __vector {
    int *data;
    size_t len;
    size_t cap;
} Vector;


// Create a new vector
//
// @cap: capacity of Vector (if 0, default value will be used)
//
// @ret: Pointer to new Vector
Vector *vec_new(const size_t cap);

// Free a vector
//
// @vp: Pointer to a Vector
void vec_free(Vector *vp);

// Add a new value to Vector
//
// @vp: Pointer to a Vector
// @val: value
void vec_append(Vector *vp, int val);


// Print a Vector
//
// @vp: Pointer to a Vector
void vec_print(Vector *vp, const char *name);

#endif // AOC_2021_D4_VECTOR_H
