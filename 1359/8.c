// 洋葱的眼泪
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t min(int32_t x, int32_t y) {
    return x < y ? x : y;
}
int32_t layer(int32_t x, int32_t y, int32_t right, int32_t bottom) {
    int32_t to_top = y;
    int32_t to_bottom = bottom - 1 - y;
    int32_t to_left = x;
    int32_t to_right = right - 1 - x;
    int32_t layer = min(min(to_top, to_bottom), min(to_left, to_right));
    return layer + 1;
}
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);
    int32_t cut_layer;
    scanf("%" PRIi32, &cut_layer);

    int32_t result = 0;
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t number;
            scanf("%" PRIi32, &number);
            int32_t current_layer = layer(j, i, number_of_one_line, line);
            if (current_layer == cut_layer) {
                result += number;
            }
        }
    }

    printf("%" PRIi32 "\n", result);
    return 0;
}
