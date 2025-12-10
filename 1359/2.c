// 出勤记录统计
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    char array[3] = {'P', 'P', 'P'};
    int32_t absent_count = 0;
    bool not_late_for_3_days = true;
    for (int32_t i = 0;; i++) {
        array[i % 3] = getchar();
        switch (array[i % 3]) {
            case 'A': {
                absent_count++;
                break;
            }
            case 'L': {
                if (array[0] == 'L' && array[1] == 'L' && array[2] == 'L') {
                    not_late_for_3_days = false;
                }
                break;
            }
            case '\n': {
                goto print_result;
            }
        }

        if (absent_count >= 2 || !not_late_for_3_days) {
            goto print_result;
        }
    }

print_result:
    if (absent_count < 2 && not_late_for_3_days) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
