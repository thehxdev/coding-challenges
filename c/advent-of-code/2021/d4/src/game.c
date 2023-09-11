#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "vector.h"
#include "board.h"
#include "game.h"
#include "str.h"

#define BUFF_SIZE 256


static Game *game_new(const size_t cap) {
    Game *g = (Game*) malloc(sizeof(Game));
    g->b_len = 0;
    g->nums = NULL;
    g->b_cap = cap;
    g->boards = (Board**) calloc(sizeof(Board*), cap);

    return g;
}


static void game_add_board(Game *gp, Board *bp) {
    if (gp->b_len % gp->b_cap == 0) {
        size_t new_size = sizeof(Board*) * (gp->b_len + gp->b_cap);
        gp->boards = (Board**) realloc(gp->boards, new_size);
    }

    gp->boards[gp->b_len] = bp;
    gp->b_len += 1;
}


static void extract_boards(Game *gp, Str_Vec *lines) {
    Board *tmp = NULL;
    char buff[1024] = { 0 };
    for (size_t i = 1; i < lines->len; i++) {
        if (i % 5 == 0) {
            sprintf(buff, "%s\n%s\n%s\n%s\n%s",
                    lines->strs[i - 4],
                    lines->strs[i - 3],
                    lines->strs[i - 2],
                    lines->strs[i - 1],
                    lines->strs[i - 0]);
            tmp = make_board(buff);
            game_add_board(gp, tmp);
        }
    }
}


Game *parse_input(FILE *fp) {
    Game *g = game_new(50);
    char *input_content = read_file(fp);
    Str_Vec *lines = str_split(input_content, "\n");

    extract_boards(g, lines);
    g->nums = make_numbers_vector(lines->strs[0]);
    
    strvec_free(lines);
    free(input_content);
    return g;
}


static bool check_rows(Board *bp) {
    for (size_t i = 0; i < bp->height; i++) {
        Vector *tmp = &bp->rows[i];
        for (size_t j = 0; j < tmp->len; j++)
            if (tmp->data[j] != -1)
                return false;
    }
    return true;
}


static bool check_columns(Board *bp) {
    Vector *row1 = &bp->rows[0];
    Vector *row2 = &bp->rows[1];
    Vector *row3 = &bp->rows[2];
    Vector *row4 = &bp->rows[3];
    Vector *row5 = &bp->rows[4];

    for (size_t i = 0; i < bp->width; i++) {
        if ((row1->data[i] & row2->data[i] & row3->data[i] & row4->data[i] & row5->data[i]) == -1)
            return true;
    }
    return false;
}


static Board *check_board_win(Game *gp) {
    Board *tmp = NULL;
    for (size_t i = 0; i < gp->b_len; i++) {
        tmp = gp->boards[i];
        if (check_rows(tmp) || check_columns(tmp))
            return tmp;
    }
    return NULL;
}


static void play_one_number(Game *gp, int num) {
    Board *btmp = NULL;
    Vector *vtmp = NULL;
    for (size_t i = 0; i < gp->b_len; i++) {
        btmp = gp->boards[i];
        for (size_t j = 0; j < btmp->height; j++) {
            vtmp = &btmp->rows[j];
            for (size_t z = 0; z < vtmp->len; z++)
                if (vtmp->data[z] == num)
                    vtmp->data[z] = -1;
        }
    }
}


static int sum_board_score(Board *bp) {
    Vector *tmp = NULL;
    int sum = 0;
    for (size_t i = 0; i < bp->height; i++) {
        tmp = &bp->rows[i];
        for (size_t j = 0; j < tmp->len; j++) {
            if (tmp->data[j] == -1)
                continue;
            sum += tmp->data[j];
        }
    }
    return sum;
}


int solve_ch1(Game *gp) {
    int *nums = gp->nums->data;
    Board *winner = NULL;
    int current_num = 0;
    for (size_t i = 0; i < gp->nums->len; i++) {
        current_num = nums[i];
        play_one_number(gp, current_num);
        if ((winner = check_board_win(gp)) != NULL)
            break;
    }

    if (winner != NULL)
        return sum_board_score(winner) * current_num;
    return 0;
}


void game_free(Game *gp) {
    if (gp) {
        for (size_t i = 0; i < gp->b_len; i++)
            board_free(gp->boards[i]);
        free(gp->boards);
        vec_free(gp->nums);
        free(gp);
    }
}


void game_print(Game *gp) {
    vec_print(gp->nums, "Nums");

    for (size_t i = 0; i < gp->b_len; i++) {
        printf("\n");
        board_print(gp->boards[i]);
    }
}
