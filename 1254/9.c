// 三角形形状
#include <stdint.h>
#include <stdio.h>

int min(int number_1, int number_2) {
    return number_1 > number_2 ? number_2 : number_1;
}
int max(int number_1, int number_2) {
    return number_1 > number_2 ? number_1 : number_2;
}
int main(void) {
    int32_t count;
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        int32_t a, b, c;
        scanf("%d,%d,%d", &a, &b, &c);
        getchar();

        // to make sure a < b < c
        if (a > b) {
            int32_t temp = a;
            a = b;
            b = temp;
        }
        if (b > c) {
            int32_t temp = b;
            b = c;
            c = temp;
        }
        if (a > b) {
            int32_t temp = a;
            a = b;
            b = temp;
        }

        if (a <= 0 || a + b <= c) {
            printf("illegal\n");
            continue;
        }

        int discriminative = a * a + b * b - c * c;
        if (discriminative < 0) {
            printf("obtuse\n");
        } else if (discriminative > 0) {
            printf("acute\n");
        } else {
            printf("right\n");
        }
    }
    return 0;
}
