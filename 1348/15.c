// 选位置
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
const int32_t MOD = 998244353;
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t row;
    scanf("%" PRIi32, &row);
    int32_t line_of_teacher, row_of_teacher;
    scanf("%" PRIi32, &line_of_teacher);
    scanf("%" PRIi32, &row_of_teacher);
    line_of_teacher -= 1;
    row_of_teacher -= 1;

    int32_t potential = 1;

    for (int32_t i = 0; i < row; i++) {
        int32_t factor = line - 1;

        if (i == 0 || i == row - 1) {
            if (line == 3 && line_of_teacher == 1) {
                factor += 1;
            } else if (line <= 2) {
                factor += 1;
            }
        }

        if (i == row_of_teacher) {
            factor = 0;
        } else if (i == row_of_teacher - 1 || i == row_of_teacher + 1) {
            if (0 < line_of_teacher && line_of_teacher < line - 1) {
                factor = line - 3;
            } else if (line != 1) {
                // line == 2 or y == 0 or y == line - 1
                factor = line - 2;
            } else {
                // line == 1
                factor = line - 1;
            }
        }

        if (factor != 0) {
            potential = (potential * factor) % MOD;
        }
        printf("factor: %" PRIi32, factor);
        printf(" potential: %" PRIi32 "\n", potential);
    }
    printf("%" PRIi32 "\n", potential % MOD);
}
