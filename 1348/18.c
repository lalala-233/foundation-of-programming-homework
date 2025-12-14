// 站岗
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
bool have_enough_safety(
    const int32_t* current,
    int32_t length,
    int32_t difference,
    int32_t total_add
) {
    int32_t result = 0;
    for (int32_t i = 0; i < length - 1; i++) {
        result += (current[i + 1] - current[i] - 1) / difference;
        if (result > total_add) {
            return false;
        }
    }
    return true;
}
int32_t min_difference(
    const int32_t* current,
    int32_t length,
    int32_t total_add,
    int32_t lowerbound,
    int32_t upperbound
) {
    if (lowerbound == upperbound) {
        return lowerbound;
    }
    int32_t mid = (lowerbound + upperbound) / 2;
    if (have_enough_safety(current, length, mid, total_add)) {
        return min_difference(current, length, total_add, lowerbound, mid);
    } else {
        return min_difference(current, length, total_add, mid + 1, upperbound);
    }
}
int32_t main(void) {
    int32_t length;
    scanf("%" PRIi32, &length);
    int32_t current_number;
    scanf("%" PRIi32, &current_number);
    int32_t total_add;
    scanf("%" PRIi32, &total_add);

    int32_t* current = malloc(sizeof(int32_t) * current_number);
    for (int32_t i = 0; i < current_number; i++) {
        scanf("%" PRIi32, &current[i]);
    }
    int32_t difference = min_difference(current, current_number, total_add, 0, length);
    printf("%" PRIi32 "\n", difference);
    free(current);
    return 0;
}
