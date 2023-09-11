#ifndef AOC_2021_D4_BOARD_H
#define AOC_2021_D4_BOARD_H

// A board is just a 5x5 Matrix

#include "vector.h"


typedef struct __board {
    Vector *rows;
    size_t width;
    size_t height;
} Board;


Board *board_init(const size_t width, const size_t height);

void board_set_row(Board *bp, Vector *vp, size_t row_idx);

void board_free(Board *bp);


void board_print(Board *bp);

#endif // AOC_2021_D4_BOARD_H
