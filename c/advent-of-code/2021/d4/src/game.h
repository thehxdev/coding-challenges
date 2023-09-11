#ifndef AOC_2021_D4_GAME_H
#define AOC_2021_D4_GAME_H

#include <stdio.h>
#include "board.h"

typedef struct __game {
    Board **boards;
    Vector *nums;
    size_t b_len;
    size_t b_cap;
} Game;


Game *parse_input(FILE *fp);

void game_free(Game *gp);

int solve_ch1(Game *gp);

void game_print(Game *gp);

#endif
