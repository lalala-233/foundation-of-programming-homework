// 排队动物
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
void process() {
    int32_t length;
    scanf("%" PRIi32, &length);
    int32_t* expected = malloc(sizeof(int32_t) * length);
    for (int32_t i = 0; i < length; i++) {
        scanf("%" PRIi32, &expected[i]);
    }
    bool all_answer_right = true;
    int32_t* actual = malloc(sizeof(int32_t) * length);
    int32_t actual_len = 0;
    for (int32_t i = 0, expected_index = 0; i < length; i++) {
        int32_t number;
        scanf("%" PRIi32, &number);

        if (all_answer_right && actual_len - 1 >= 0) {
            if (actual[actual_len - 1] == number) {
                actual_len--;
                continue;
            }
            for (int32_t j = 0; j < actual_len - 1; j++) {
                if (actual[j] == number) {
                    all_answer_right = false;
                    break;
                }
            }
        }
        if (all_answer_right) {
            while (expected[expected_index] != number) {
                actual[actual_len] = expected[expected_index];
                actual_len++;
                expected_index++;
            }
            expected_index++;
        }
    }
    if (all_answer_right) {
        printf("YES\n");
    } else {
        printf("N0\n");
    }
    free(expected);
    free(actual);
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);

    for (int32_t i = 0; i < count; i++) {
        process();
    }
    return 0;
}
