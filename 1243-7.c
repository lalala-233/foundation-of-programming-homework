// 三点共线 1
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // (x1 - x2) / (y1 - y2) == (x1 - x3) / (y1 - y3)
    bool is_collinear = ((x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2));

    printf("%d\n", (int32_t)is_collinear);
    return 0;
}