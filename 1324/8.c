// Zig-Zag 模式填充矩阵
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
typedef enum {
    Down,
    LeftDown,
    Right,
    RightTop,
    End,
} Direction;
void update_unchecked(Direction current, int32_t* x, int32_t* y) {
    switch (current) {
        case Down: {
            *y += 1;
            break;
        }
        case LeftDown: {
            *x -= 1;
            *y += 1;
            break;
        }
        case Right: {
            *x += 1;
            break;
        }
        case RightTop: {
            *x += 1;
            *y -= 1;
            break;
        }
        case End: {
            // Unreachable
            printf("Unreachable is reached!\n");
            break;
        }
    }
}
Direction next_direction(Direction current, int32_t x, int32_t y, int32_t max_x, int32_t max_y) {
    switch (current) {
        case Down: {
            if (x == 0) {
                return RightTop;
            }
            if (x == max_x) {
                return LeftDown;
            }
            // Unreachable
            printf("Unreachable is reached!\n");
            break;
        }
        case LeftDown: {
            if (y == max_y) {
                return Right;
            } else if (x == 0) {
                return Down;
            }
            return LeftDown;
            break;
        }
        case Right: {
            if (y == 0) {
                return LeftDown;
            }
            if (y == max_y) {
                return RightTop;
            }
            // Unreachable
            printf("Unreachable is reached!\n");
            break;
        }
        case RightTop: {
            if (x == max_x) {
                return Down;
            } else if (y == 0) {
                return Right;
            }
            return RightTop;
            break;
        }
        case End: {
            // Unreachable
            printf("Unreachable is reached!\n");
            return End;
            break;
        }
    }
    // Unreachable
    printf("Unreachable is reached!\n");
    return End;
}
int32_t main(void) {
    int32_t total_y, total_x;
    scanf("%" PRIi32 " %" PRIi32, &total_y, &total_x);
    // top-left is (0, 0)
    int32_t map[total_y][total_x];

    Direction direction = RightTop; // Or LeftDown
    for (int i = 1, x = 0, y = 0; i <= total_x * total_y; i++) {
        map[y][x] = i;
        direction = next_direction(direction, x, y, total_x - 1, total_y - 1);
        update_unchecked(direction, &x, &y);
    }

    for (int32_t y = 0; y < total_y; y++) {
        printf("%" PRIi32, map[y][0]);
        for (int32_t x = 1; x < total_x; x++) {
            printf(" %" PRIi32, map[y][x]);
        }
        putchar('\n');
    }
    return 0;
}
