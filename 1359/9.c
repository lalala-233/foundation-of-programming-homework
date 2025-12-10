// 日期距离
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
const char* MONTH_S[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
const int32_t COMMON_YEAR_DAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int32_t LEAP_YEAR_DAY[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int32_t as_days(int32_t year, int32_t month, int32_t day) {
    const int32_t* year_day;
    if (year % 4 == 0) {
        year_day = LEAP_YEAR_DAY;
    } else {
        year_day = COMMON_YEAR_DAY;
    }
    int32_t days = 0;
    days += year * 365;
    if (year > 0) {
        // leap year
        days += ((year - 1) / 4) + 1;
    }
    for (int32_t i = 0; i < month - 1; i++) {
        days += year_day[i];
    }
    days += day;
    return days;
}
bool as_yy_mm_dd(int32_t year, int32_t month, int32_t day) {
    const int32_t* year_day;
    if (year % 4 == 0) {
        year_day = LEAP_YEAR_DAY;
    } else {
        year_day = COMMON_YEAR_DAY;
    }
    bool result = true;
    result = result && 1 <= month && month <= 12;
    result = result && 1 <= day && day <= year_day[month - 1];
    return result;
}
int32_t read_data() {
    int32_t result = 0;
    result += getchar() - '0';
    result *= 10;
    result += getchar() - '0';
    char _use_less = getchar();
    return result;
}
int32_t main(void) {
    int32_t left = read_data();
    int32_t middle = read_data();
    int32_t right = read_data();
    bool is_yy_mm_dd = as_yy_mm_dd(left, middle, right);
    bool is_mm_dd_yy = as_yy_mm_dd(right, left, middle);

    if (is_mm_dd_yy && is_yy_mm_dd) {
        int32_t days_difference = as_days(left, middle, right) - as_days(right, left, middle);
        printf("%" PRIi32 "\n", abs(days_difference));
    } else if (is_yy_mm_dd) {
        printf("%s %" PRIi32 ", 20%02" PRIi32 "\n", MONTH_S[middle - 1], right, left);
    } else if (is_mm_dd_yy) {
        printf("%s %" PRIi32 ", 20%02" PRIi32 "\n", MONTH_S[left - 1], middle, right);
    }

    return 0;
}
