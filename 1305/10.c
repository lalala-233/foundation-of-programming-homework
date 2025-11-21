// 统计字符串中的数字个数
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define IMAGE_SIZE 6
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    char _new_line = getchar();

    for (int32_t i = 0; i < count; i++) {
        int32_t result = 0;
        char character = getchar();
        bool left_is_number = false;

        while (character != '\n') {
            if (isdigit(character)) {
                if (!left_is_number) {
                    result++;
                }
                left_is_number = true;
            } else {
                left_is_number = false;
            }
            character = getchar();
        }
        printf("%" PRIi32 "\n", result);
    }
    return 0;
}
