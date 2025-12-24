// 回旋十字斩
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int32_t get(int32_t* array, int32_t line, int32_t number_of_one_line, int32_t i, int32_t j) {
    if (i < 0 || i >= line || j < 0 || j >= number_of_one_line) {
        return 0;
    }
    int32_t index = i * number_of_one_line + j;
    return array[index];
}
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);
    int32_t threshold;
    scanf("%" PRIi32, &threshold);

    int32_t* array = malloc(sizeof(int32_t) * line * number_of_one_line);

    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            scanf("%" PRIi32, &array[index]);
        }
    }
    int32_t count = 0;
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t energy = 0;
            energy += get(array, line, number_of_one_line, i - 1, j);
            energy += get(array, line, number_of_one_line, i, j - 1);
            energy += get(array, line, number_of_one_line, i, j);
            energy += get(array, line, number_of_one_line, i, j + 1);
            energy += get(array, line, number_of_one_line, i + 1, j);
            if (energy > threshold) {
                count++;
            }
        }
    }
    printf("%" PRIi32 "\n", count);
    free(array);
    return 0;
}
