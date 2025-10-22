// 时间转换
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t seconds;
    scanf("%d", &seconds);
    int32_t hour = seconds / 3600;
    int32_t minute = (seconds % 3600) / 60;
    int32_t second = (seconds % 3600) % 60;

    printf("%02d:%02d:%02d\n", hour, minute, second);

    return 0;
}