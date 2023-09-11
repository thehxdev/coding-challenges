#include <stdio.h>
#include <stdlib.h>

#define __USE_XOPEN_EXTENDED // for strdup
#define __USE_POSIX // for strtok_r
#include <string.h>

#include "vector.h"
#include "board.h"
#include "str.h"


Vector *make_numbers_vector(const char *line) {
    if (line == NULL)
        return NULL;

    Vector *v = vec_new(0);
    char *str = strdup(line);
    int current = 0;

    char *token = strtok(str, ",");
    while (token != NULL) {
        current = atoi(token);
        vec_append(v, current);
        token = strtok(NULL, ",");
    }

    free(str);
    return v;
}


Board *make_board(const char *str_board) {
    if (str_board == NULL)
        return NULL;

    char *tmp_board = strdup(str_board);
    Board *board = board_init(5, 5);
    Vector *v_row  = NULL;

    char *row_sptr;
    char *s_row = strtok_r(tmp_board, "\n", &row_sptr);

    int i = 0;
    int num = 0;
    char *num_sptr;
    char *s_num = NULL;

    while(s_row != NULL) {
        s_num = strtok_r(s_row, " ", &num_sptr);
        v_row = vec_new(5);

        while (s_num != NULL) {
            num = atoi(s_num);
            vec_append(v_row, num);
            s_num = strtok_r(NULL, " ", &num_sptr);
        }

        board_set_row(board, v_row, i);
        vec_free(v_row);

        s_row = strtok_r(NULL, "\n", &row_sptr);
        i++;
    }
    
    free(tmp_board);
    return board;
}


static Str_Vec *strvec_init(const size_t cap) {
    Str_Vec *sv = (Str_Vec*) malloc(sizeof(Str_Vec));
    sv->len = 0;
    sv->cap = cap;
    sv->strs = (char**) calloc(sizeof(char*), sv->cap);

    return sv;
}


static void strvec_append(Str_Vec *svp, const char *str) {
    if (svp == NULL || str == NULL)
        return;

    if (svp->len % svp->cap == 0) {
        size_t new_size = sizeof(char*) * (svp->len + svp->cap);
        svp->strs = (char**) realloc(svp->strs, new_size);
    }

    size_t input_len = strlen(str);
    svp->strs[svp->len] = (char*) malloc(input_len + 1);
    strcpy(svp->strs[svp->len], str);
    svp->len += 1;
}


Str_Vec *str_split(const char *s, const char *delim) {
    char *str = strdup(s);
    char *str_sptr;
    Str_Vec *sv = strvec_init(20);

    char *token = strtok_r(str, delim, &str_sptr);
    while (token != NULL) {
        strvec_append(sv, token);
        token = strtok_r(NULL, delim, &str_sptr);
    }

    free(str);
    return sv;
}


void strvec_free(Str_Vec *svp) {
    if (svp) {
        for (size_t i = 0; i < svp->len; i++)
            free(svp->strs[i]);
        free(svp->strs);
        free(svp);
    }
}


char *read_file(FILE *fp) {
    fseek(fp, SEEK_SET, SEEK_END);
    size_t len = ftell(fp);
    rewind(fp);

    char *content = (char*) calloc(sizeof(char), len + 1);
    fread(content, sizeof(char), len, fp);

    return content;
}
