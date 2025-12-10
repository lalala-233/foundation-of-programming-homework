// 像素传送门
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);
    int32_t right_step;
    scanf("%" PRIi32, &right_step);
    int32_t down_step;
    scanf("%" PRIi32, &down_step);

    char* playground = malloc(sizeof(char) * line * number_of_one_line);
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            char current = getchar();
            while (isspace(current)) {
                current = getchar();
            }
            int32_t index = i * number_of_one_line + j;
            playground[index] = current;
        }
    }

    right_step = right_step % number_of_one_line;
    int32_t new_start_of_one_line = number_of_one_line - right_step;
    down_step = down_step % line;
    int32_t new_start_of_line = line - down_step;
    for (int32_t i = new_start_of_line; i < line; i++) {
        for (int32_t j = new_start_of_one_line; j < number_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            putchar(playground[index]);
        }
        for (int32_t j = 0; j < new_start_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            putchar(playground[index]);
        }
        printf("\n");
    }
    for (int32_t i = 0; i < new_start_of_line; i++) {
        for (int32_t j = new_start_of_one_line; j < number_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            putchar(playground[index]);
        }
        for (int32_t j = 0; j < new_start_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            putchar(playground[index]);
        }
        printf("\n");
    }
    free(playground);
    return 0;
}
