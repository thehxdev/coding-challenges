#include <stdio.h>
#include <file.h>
#include <ds/vector.h>
#include <general.h>

#define BUFF_SIZE 128

int main(void) {
    char *buff = (char*) calloc(sizeof(char), BUFF_SIZE + 1);
    const char *input_file_path = (char*) "./input";
    FILE *fp = fopen(input_file_path, "r");
    if (fp == NULL)
        return 1;


    Vector *prism = vec_new();
    int x = 0;

    while (fgets(buff, BUFF_SIZE, fp) != NULL) {
        str_split(prism, buff, "x");

        for (uint32_t i = 0; i < prism->length; i += 1) {
            x = str_to_int((char*)vec_get(prism, i));
            vec_set(prism, i,&x, sizeof(x));
        }

        printf("[ ");
        for (uint32_t i = 0; i < prism->length; i += 1)
            printf("%d ", *(int*)vec_get(prism, i));
        printf("]\n");

        vec_clean(prism);
    }

    return 0;
}
