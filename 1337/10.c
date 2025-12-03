// 大整数加法
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define LEN (500 + 1)
int32_t read_string(char number[LEN]) {
    char current = getchar();
    for (int32_t i = 0;; i++) {
        number[i] = current;
        if (isspace(current)) {
            number[i] = '\0';
            return i;
        }
        current = getchar();
    }
}
void add(char longer[LEN], char shorter[LEN], int32_t longer_len, int32_t shorter_len) {
    for (int32_t i = 1; longer_len - i >= 0; i++) {
        if (shorter_len - i >= 0) {
            longer[longer_len - i] += shorter[shorter_len - i] - '0';
        }
        if (longer[longer_len - i] > '9') {
            longer[longer_len - i] -= 10;
            if (longer_len - i - 1 < 0) {
                printf("1");
                break;
            } else {
                longer[longer_len - i - 1] += 1;
            }
        }
    }
    printf("%s\n", longer);
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    char _new_line = getchar();
    for (int32_t i = 0; i < count; i++) {
        char left[LEN];
        int32_t left_len = read_string(left);
        char right[LEN];
        int32_t right_len = read_string(right);
        if (left_len > right_len) {
            add(left, right, left_len, right_len);
        } else {
            add(right, left, right_len, left_len);
        }
    }
}
