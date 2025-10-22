// 平方根
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t count;
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);
        getchar();

        if (number >= 0) {
            double root = sqrt(number);
            printf("%.2f\n", root);
        } else {
            printf("ERROR\n");
        }
    }
    return 0;
}
