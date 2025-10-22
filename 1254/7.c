// 判断闰年
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_leap_year(int32_t year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int main(void) {
    int32_t count;
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        int32_t year;
        scanf("%d", &year);
        getchar();

        if (is_leap_year(year) && year > 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
