// 判断某个日期是该年第几天
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_leap_year(int32_t year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int32_t count_days(const int32_t months[12], int32_t month, int32_t day) {
    int32_t days = 0;
    for (int i = 0; i < month - 1; i++) {
        days += months[i];
    }
    days += day;

    return days;
}

int32_t count_common_days(int32_t month, int32_t day) {
    const int32_t common_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return count_days(common_year, month, day);
}

int32_t count_leap_days(int32_t month, int32_t day) {
    const int32_t leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return count_days(leap_year, month, day);
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t year, month, day;
        scanf("%d %d %d", &year, &month, &day);

        int days = 0;
        if (is_leap_year(year)) {
            days = count_leap_days(month, day);
        } else {
            days = count_common_days(month, day);
        }

        printf("%d\n", days);
    }
    return 0;
}
