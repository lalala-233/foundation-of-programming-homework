// 韩信点兵
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t rest_of_3, rest_of_5, rest_of_7;
        scanf("%d %d %d", &rest_of_3, &rest_of_5, &rest_of_7);

        for (int32_t i = 10; i <= 100; i++) {
            if (i % 3 == rest_of_3 && i % 5 == rest_of_5 && i % 7 == rest_of_7) {
                printf("%d\n", i);
                break;
            } else if (i == 100) {
                printf("Impossible\n");
            }
        }
    }
    return 0;
}
