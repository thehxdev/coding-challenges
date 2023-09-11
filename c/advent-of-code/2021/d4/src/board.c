#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "vector.h"


Board *board_init(const size_t width, const size_t height) {
    Board *b = (Board*) malloc(sizeof(Board));
    if (b == NULL)
        return NULL;

    b->width  = width;
    b->height = height;
    b->rows   = (Vector*) calloc(sizeof(Vector), height);
    if (b->rows == NULL) {
        free(b);
        return NULL;
    }

    Vector *v = NULL;
    for (size_t i = 0; i < height; i++) {
        v = vec_new(width + 1);
        if (v == NULL) {
            board_free(b);
            return NULL;
        }
        b->rows[i] = *v;
        free(v);
    }

    return b;
}


void board_set_row(Board *bp, Vector *vp, size_t row_idx) {
    if (vp == NULL || bp == NULL)
        return;

    if (vp->len != bp->width || row_idx >= bp->height)
        return;

    Vector *row = &bp->rows[row_idx];
    for (size_t i = 0; i < vp->len; i++) {
        vec_append(row, vp->data[i]);
    }
}


void board_free(Board *bp) {
    if (bp) {
        for (size_t i = 0; i < bp->height; i++)
            free(bp->rows[i].data);
        free(bp->rows);
        free(bp);
    }
}


void board_print(Board *bp) {
    if (bp != NULL) {
        char name[32] = { 0 };
        for (size_t i = 0; i < bp->height; i++) {
            sprintf(name, "row %lu", i);
            vec_print(&bp->rows[i], name);
        }
    }
}
