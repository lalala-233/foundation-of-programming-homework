// 换位置
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t main(void) {
    int32_t row;
    scanf("%" PRIi32, &row);
    bool row_should_draw[row];
    for (int32_t i = 0; i < row; i++) {
        row_should_draw[i] = false;
    }

    int32_t column;
    scanf("%" PRIi32, &column);
    bool column_should_draw[column];
    for (int32_t i = 0; i < column; i++) {
        column_should_draw[i] = false;
    }

    int32_t line_of_row;
    scanf("%" PRIi32, &line_of_row);
    int32_t line_of_column;
    scanf("%" PRIi32, &line_of_column);

    for (int32_t i = 0; i < line_of_row; i++) {
        int32_t line;
        scanf("%" PRIi32, &line);
        row_should_draw[line - 1] = true;
    }

    for (int32_t i = 0; i < line_of_column; i++) {
        int32_t line;
        scanf("%" PRIi32, &line);
        column_should_draw[line - 1] = true;
    }

    for (int32_t i = 0; i < row; i++) {
        for (int32_t j = 0; j < column; j++) {
            char character;
            if (row_should_draw[i] && column_should_draw[j]) {
                character = '+';
            } else if (row_should_draw[i]) {
                character = '-';
            } else if (column_should_draw[j]) {
                character = '|';
            } else {
                character = '0';
            }
            printf("%c", character);
        }
        printf("\n");
    }
    return 0;
}
