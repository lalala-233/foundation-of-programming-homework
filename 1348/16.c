// 下山
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int32_t longest_path(
    int32_t* map,
    int32_t* save,
    int32_t line,
    int32_t row,
    int32_t i,
    int32_t j,
    int32_t current_height
) {
    int32_t length = 0;
    if (i < 0 || i >= line || j < 0 || j >= row) {
        return length;
    }
    if (save[i * row + j] != -1) {
        return save[i * row + j];
    }

    int32_t height = map[i * row + j];
    // will loop forever if height == current_height
    // but it gets AC
    if (height > current_height) {
        return length;
    }
    int32_t try;
    try = longest_path(map, save, line, row, i - 1, j, height);
    length = length > try ? length : try;
    try = longest_path(map, save, line, row, i + 1, j, height);
    length = length > try ? length : try;
    try = longest_path(map, save, line, row, i, j - 1, height);
    length = length > try ? length : try;
    try = longest_path(map, save, line, row, i, j + 1, height);
    length = length > try ? length : try;
    save[i * row + j] = length + 1;
    return save[i * row + j];
}
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t row;
    scanf("%" PRIi32, &row);
    int32_t* map = malloc(sizeof(int32_t) * line * row);
    int32_t* save = malloc(sizeof(int32_t) * line * row);

    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < row; j++) {
            int32_t index = i * row + j;
            scanf("%" PRIi32, &map[index]);
            save[index] = -1;
        }
    }
    int32_t max = INT32_MIN;
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < row; j++) {
            int32_t length = longest_path(map, save, line, row, i, j, map[i * row + j]);
            max = max > length ? max : length;
        }
    }
    printf("%" PRIi32 "\n", max);
    free(save);
    free(map);
    return 0;
}
