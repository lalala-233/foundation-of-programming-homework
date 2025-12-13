// 纪念日
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
const int32_t YEAR_2024_DAY[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int32_t HOURS_PER_DAY = 24;
const int32_t MINUTES_PER_HOUR = 60;
int32_t as_minutes(int32_t month, int32_t day, int32_t hour, int32_t minute) {
    int32_t days = 0;
    for (int32_t i = 0; i < month - 1; i++) {
        days += YEAR_2024_DAY[i];
    }
    days += day;
    int32_t hours = days * HOURS_PER_DAY + hour;
    int32_t minutes = hours * MINUTES_PER_HOUR + minute;
    return minutes;
}
int32_t main(void) {
    int32_t mm_dd_hh_mm[4];

    for (int32_t i = 0; i < 4; i++) {
        scanf("%" PRIi32, &mm_dd_hh_mm[i]);
    }
    int32_t start_time = as_minutes(mm_dd_hh_mm[0], mm_dd_hh_mm[1], mm_dd_hh_mm[2], mm_dd_hh_mm[3]);

    for (int32_t i = 0; i < 4; i++) {
        scanf("%" PRIi32, &mm_dd_hh_mm[i]);
    }
    int32_t end_time = as_minutes(mm_dd_hh_mm[0], mm_dd_hh_mm[1], mm_dd_hh_mm[2], mm_dd_hh_mm[3]);

    printf("%" PRIi32 "\n", end_time - start_time);

    return 0;
}
