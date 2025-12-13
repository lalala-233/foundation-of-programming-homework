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

    int64_t potential = 1;

    for (int32_t i = 0; i < row; i++) {
        int32_t factor = line - 1;

        if (i == row_of_teacher) {
            factor = 1;
        } else if (i == row_of_teacher - 1 || i == row_of_teacher + 1) {
            // If line <= 3, it may be 0
            // we don't know if it is right, but it gets AC
            factor = line - 1;
            if (line_of_teacher > 0) {
                factor -= 1;
            }
            if (line_of_teacher < line - 1) {
                factor -= 1;
            }
        }

        potential = (potential * factor) % MOD;

        // printf("factor: %" PRIi32, factor);
        // printf(" potential: %" PRIi64 "\n", potential);
    }
    printf("%" PRIi64 "\n", potential % MOD);
}
