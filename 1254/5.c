// 两个圆的位置关系
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t circle_1_x, circle_1_y, radius_1;
    int32_t circle_2_x, circle_2_y, radius_2;
    scanf("%d %d %d", &circle_1_x, &circle_1_y, &radius_1);
    scanf("%d %d %d", &circle_2_x, &circle_2_y, &radius_2);

    int32_t delta_x = circle_1_x - circle_2_x;
    int32_t delta_y = circle_1_y - circle_2_y;
    int32_t distance_square = delta_x * delta_x + delta_y * delta_y;

    int32_t radius_sum_square = (radius_1 + radius_2) * (radius_1 + radius_2);
    int32_t radius_difference_square = (radius_1 - radius_2) * (radius_1 - radius_2);

    int32_t result;

    if (distance_square > radius_sum_square) {
        result = 0;
    } else if (distance_square == radius_sum_square) {
        result = 1;
    } else if (distance_square > radius_difference_square) {
        result = 2;
    } else if (distance_square == radius_difference_square) {
        result = 3;
    } else {
        result = 4;
    }

    if (distance_square == 0) {
        result = 5;
    }

    printf("%d\n", result);

    return 0;
}
