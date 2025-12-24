// 鞍点猎人
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t get_line_max(int32_t* array, int32_t number_of_one_line) {
    int32_t line_max = INT32_MIN;
    for (int32_t i = 0; i < number_of_one_line; i++) {
        line_max = line_max > array[i] ? line_max : array[i];
    }
    return line_max;
}
int32_t get_row_min(int32_t* array, int32_t line, int32_t number_of_one_line) {
    int32_t row_min = INT32_MAX;
    for (int32_t i = 0; i < line; i++) {
        row_min = row_min < array[i * number_of_one_line] ? row_min : array[i * number_of_one_line];
    }
    return row_min;
}
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);
    int32_t* array = malloc(sizeof(int32_t) * line * number_of_one_line);

    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            scanf("%" PRIi32, &array[index]);
        }
    }

    bool already_print = false;
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t line_max = get_line_max(&array[i * number_of_one_line], number_of_one_line);
            int32_t row_min = get_row_min(&array[j], line, number_of_one_line);
            int32_t index = i * number_of_one_line + j;
            if (array[index] == line_max && array[index] == row_min) {
                printf("%" PRIi32 " ", i);
                printf("%" PRIi32 "\n", j);
                already_print = true;
            }
        }
    }

    if (!already_print) {
        printf("none\n");
    }
    free(array);
    return 0;
}
