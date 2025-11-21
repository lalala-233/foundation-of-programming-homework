// 平铺输出图案
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define IMAGE_SIZE 6
const char* IMAGE[IMAGE_SIZE] =
    {"--**-**--", "-*--*--*-", "-*-----*-", "--*---*--", "---*-*---", "----*----"};
void print_triangle(int32_t m, int32_t n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < n; k++) {
                printf("%s", IMAGE[j]);
            }
            printf("\n");
        }
    }
}
int32_t main(void) {
    int32_t m, n;
    scanf("%" PRIi32 " %" PRIi32, &m, &n);

    if (n < 1 || m < 1 || n > 5 || m > 5) {
        printf("Input Error\n");
        return 0;
    }
    print_triangle(m, n);
    return 0;
}
