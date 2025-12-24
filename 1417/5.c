// 分数求和
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    int64_t up;
    int64_t down;
} Number;
void print(Number number) {
    if (number.up == 0) {
        printf("0\n");
        return;
    }
    printf("%" PRIi64, number.up);
    if (number.down != 1) {
        printf("/%" PRIi64, number.down);
    }
    printf("\n");
}
int64_t get_max_factor(int64_t greater, int64_t less) {
    if (greater < 0) {
        return get_max_factor(-greater, less);
    }
    if (less < 0) {
        return get_max_factor(greater, -less);
    }
    if (less == 0) {
        return 1;
    }
    if (greater == less) {
        return greater;
    }
    if (greater < less) {
        return get_max_factor(less, greater);
    }
    if (greater % less == 0) {
        return less;
    } else {
        return get_max_factor(less, greater % less);
    }
}
Number simplify(Number number) {
    if (number.up == 0) {
        Number result = {0, 1};
        return result;
    }
    int64_t max_factor = get_max_factor(number.up, number.down);
    number.down /= max_factor;
    number.up /= max_factor;
    return number;
}
Number add(Number left, Number right) {
    Number result;
    int64_t max_down_factor = get_max_factor(left.down, right.down);
    result.down = left.down / max_down_factor * right.down;
    result.up = left.up * (right.down / max_down_factor) + right.up * (left.down / max_down_factor);
    return simplify(result);
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);

    Number result = {0, 1};

    for (int32_t i = 0; i < count; i++) {
        Number number;
        scanf("%" PRIi64 "/%" PRIi64, &number.up, &number.down);
        if (number.down == 0) {
            printf("error\n");
            return 0;
        }
        result = add(result, number);
    }
    print(result);
    return 0;
}
