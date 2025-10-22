// 点和圆的关系
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t circle_x, circle_y, radius, point_x, point_y;
    scanf("%d %d %d %d %d", &circle_x, &circle_y, &radius, &point_x, &point_y);

    int32_t delta_x = point_x - circle_x;
    int32_t delta_y = point_y - circle_y;
    int32_t distance_square = delta_x * delta_x + delta_y * delta_y;

    bool is_point_strictly_in_circle = distance_square < radius * radius;

    printf("%d\n", (int32_t)is_point_strictly_in_circle);

    return 0;
}
