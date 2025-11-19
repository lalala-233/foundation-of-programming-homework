// 折点计数
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t count_special_point_tool(
    int32_t count,
    int32_t result,
    int32_t left,
    int32_t middle,
    int32_t right
) {
    int32_t is_special_point = middle > right && middle > left;
    is_special_point += middle < right && middle < left;
    result += is_special_point;
    if (count == 0) {
        return result;
    }
    int32_t new;
    scanf("%d", &new);
    return count_special_point_tool(count - 1, result, middle, right, new);
}
int32_t count_special_point(int32_t count) {
    if (count < 3) {
        return 0;
    }
    int left, middle, right;
    scanf("%d %d %d", &left, &middle, &right);
    return count_special_point_tool(count - 3, 0, left, middle, right);
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);
    int32_t result = count_special_point(count);
    printf("%d\n", result);
    return 0;
}
