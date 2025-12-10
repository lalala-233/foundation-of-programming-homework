// 霓虹跑道
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
    int32_t step;
    scanf("%" PRIi32, &step);

    char* playground = malloc(sizeof(char) * line * number_of_one_line);
    for (int32_t i = 0; i < line; i++) {
        char _new_line = getchar();
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            playground[index] = getchar();
        }
    }

    step = step % number_of_one_line;
    int32_t new_start_of_one_line = number_of_one_line - step;
    for (int32_t i = 0; i < line; i++) {
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
