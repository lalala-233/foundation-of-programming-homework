// 图像的匹配
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int32_t i;
    int32_t j;
    const int32_t m;
    const int32_t n;
} Reader;
Reader origin(Reader reader) {
    reader.i = 0;
    reader.j = 0;
    return reader;
}
int32_t get_index(int32_t i, int32_t j, Reader reader) {
    return (i + reader.i) % reader.m * reader.n + (j + reader.j) % reader.n;
}
bool is_origin(Reader reader) {
    return reader.i == 0 && reader.j == 0;
}
bool eq(const int32_t* origin_image, const int32_t* expected_image, Reader reader) {
    bool eq = true;
    for (int32_t i = 0; i < reader.m; i++) {
        for (int32_t j = 0; j < reader.n; j++) {
            int32_t origin_index = get_index(i, j, reader);
            int32_t expected_index = get_index(i, j, origin(reader));
            eq = eq && origin_image[origin_index] == expected_image[expected_index];
            if (!eq) {
                return false;
            }
        }
    }
    return true;
}
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);

    Reader reader = {0, 0, line, number_of_one_line};
    int32_t* origin_image = malloc(sizeof(int32_t) * line * number_of_one_line);
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t index = get_index(i, j, reader);
            scanf("%" PRIi32, &origin_image[index]);
        }
    }
    int32_t* expected_image = malloc(sizeof(int32_t) * line * number_of_one_line);
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t index = get_index(i, j, reader);
            scanf("%" PRIi32, &expected_image[index]);
        }
    }
    int32_t step = 0;
    while (!eq(origin_image, expected_image, reader)) {
        step++;
        if (step % 2 == 1) {
            reader.j = (reader.j + reader.n - 1) % reader.n;
        } else {
            reader.i = (reader.i + reader.m - 1) % reader.m;
        }
        if (is_origin(reader)) {
            step = -1;
            break;
        }
    }
    if (step == -1) {
        printf("No\n");
    } else {
        printf("%" PRIi32 "\n", step);
    }
    free(origin_image);
    free(expected_image);
    return 0;
}
