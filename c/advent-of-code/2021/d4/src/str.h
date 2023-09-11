#ifndef AOC_2021_D4_STR_H
#define AOC_2021_D4_STR_H

#include <stdio.h>
#include "vector.h"
#include "board.h"

typedef struct __str_vec {
    char **strs;
    size_t len;
    size_t cap;
} Str_Vec;

// return malloc'd s (I know about strdup)
char *str_malloc(const char *s);

// make a vector of numbers in first line of input file
Vector *make_numbers_vector(const char *line);

// split a string to a string-vector (list of strings)
Str_Vec *str_split(const char *s, const char *delim);

// free a Str_Vec
void strvec_free(Str_Vec *svp);

// make a board from a string that rows splitted with '\n' character
Board *make_board(const char *str_board);

// read a txt file's content and store it in memory
char *read_file(FILE *fp);

#endif // AOC_2021_D4_STR_H
