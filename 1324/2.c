// 计算平均值（二）
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);

    int32_t sum = 0;
    int32_t valid_count = 0;
    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        bool is_success = (bool)scanf("%" PRIi32, &number);
        if (is_success) {
            valid_count++;
            sum += number;
        } else {
            while (true) {
                char invalid_character = getchar();
                // "n/a"
                if (invalid_character == 'a') {
                    break;
                }
            }
        }
    }
    if (valid_count == 0) {
        printf("n/a\n");
    } else {
        double average = (double)sum / valid_count;
        printf("%.2f", average);
    }
    return 0;
}
