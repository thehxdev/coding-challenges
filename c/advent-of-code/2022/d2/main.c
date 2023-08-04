#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "d2.h"

#define BUFF_SIZE 4

int main(void) {
    int res1 = 0, res2 = 0;
    char buff[BUFF_SIZE];
    const char *inputFile = "./input.txt";
    FILE *fp = fopen(inputFile, "r");
    if (fp == NULL) {
        fprintf(stderr, "ERROR: Cannot open file %s\n", inputFile);
        return 1;
    }

    while (fgets(buff, BUFF_SIZE, fp) != NULL) {
        res1 += player_score(buff[0], buff[2]);
        res2 += round_score(buff[0], buff[2]);
    }

    printf("Challenge 1: %d\n", res1);
    printf("Challenge 2: %d\n", res2);
    fclose(fp);
    return 0;
}

