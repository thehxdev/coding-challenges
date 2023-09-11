#include <stdio.h>
#include "game.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input-file-path>\n", argv[0]);
        return 1;
    } 

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "ERROR: Could not find %s file\n", argv[1]);
        return 1;
    }

    Game *game = parse_input(fp);

    int winner_score = solve_ch1(game);
    printf("Challenge 1: %d\n", winner_score);

    game_free(game);
    fclose(fp);
    return 0;
}
