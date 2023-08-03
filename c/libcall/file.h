#ifndef LIBCHALL_FILE_H
#define LIBCHALL_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


char *read_txt_file(FILE *fp) {
    fseek(fp, SEEK_SET, SEEK_END);
    uint32_t len = ftell(fp);
    rewind(fp);

    char *content = (char*) calloc(sizeof(char), len + 1);
    fread(content, sizeof(char), len, fp);

    return content;
}


#endif
