#include <stdio.h>
#include <general.h>
#include <file.h>


int main(void) {
    int current_floor = 0;
    const char *input_file_path = "./input";

    FILE *input_file = fopen(input_file_path, "r");
    if (input_file == NULL)
        return 1;

    char *input = read_txt_file(input_file);

    uint32_t i = 0;
    while (input[i] != '\0') {
        if (input[i] == '(')
            current_floor += 1;
        else if (input[i] == ')')
            current_floor -= 1;

        i += 1;
    }
    printf("Challenge 1: %d\n", current_floor);

    i = 0;
    current_floor = 0;
    while (input[i] != '\0') {
        if (input[i] == '(')
            current_floor += 1;
        else if (input[i] == ')')
            current_floor -= 1;

        if (current_floor == -1) {
            printf("Challenge 2: %u\n", i + 1);
            break;
        }

        i += 1;
    }

    free(input);
    return 0;
}
