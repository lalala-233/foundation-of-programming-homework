// 走迷宫
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t total_y, total_x;
    scanf("%" PRIi32 " %" PRIi32, &total_y, &total_x);
    // top-left is (1, 1)
    char map[total_y][total_x];
    for (int32_t i = 0; i < total_y; i++) {
        char _new_line = getchar();
        for (int32_t j = 0; j < total_x; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    int32_t count;
    scanf("%" PRIi32, &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t y, x, step;
        scanf("%" PRIi32 " %" PRIi32 " %" PRIi32, &y, &x, &step);
        for (int32_t j = 0; j < step; j++) {
            switch (map[y - 1][x - 1]) {
                case 'U': {
                    if (y == 1) {
                        y = total_y;
                    } else {
                        y--;
                    }
                    break;
                }
                case 'D': {
                    if (y == total_y) {
                        y = 1;
                    } else {
                        y++;
                    }
                    break;
                }
                case 'L': {
                    if (x == 1) {
                        x = total_x;
                    } else {
                        x--;
                    }
                    break;
                }
                case 'R': {
                    if (x == total_x) {
                        x = 1;
                    } else {
                        x++;
                    }
                    break;
                }
            }
        }
        printf("%" PRIi32 " %" PRIi32 "\n", y, x);
    }
    return 0;
}
