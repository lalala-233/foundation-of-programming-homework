// 今天星期几
#include <stdint.h>
#include <stdio.h>

int main(void) {
    const int32_t DAY_0 = 1; // 2025.1.1
    const int32_t FIRST_DAY = 3; // Wednesday
    int32_t day;
    scanf("%d", &day);

    int32_t today = (FIRST_DAY + day - DAY_0) % 7;
    today = today == 0 ? 7 : today; // 0 is sunday

    printf("%d\n", today);
    return 0;
}