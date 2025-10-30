// 判断直角三角形
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a >= b) {
            int32_t tmp = a;
            a = b;
            b = tmp;
        }
        if (b >= c) {
            int32_t tmp = b;
            b = c;
            c = tmp;
        }
        if (a >= b) {
            int32_t tmp = a;
            a = b;
            b = tmp;
        }

        if (a + b <= c) {
            printf("No\n");
        } else if (a * a + b * b == c * c) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
