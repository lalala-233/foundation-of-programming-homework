// 乘积符号
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    size_t negative_count = (int32_t)(a < 0) + (int32_t)(b < 0) + (int32_t)(c < 0);

    if (negative_count % 2 == 0) {
        printf("1\n");
    } else {
        printf("-1\n");
    }
    return 0;
}