// 计算题
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
const int32_t COUNT = 3;
const int32_t LEN = 100000 + 1;
int32_t match(const char* s, char expected) {
    int32_t offset = 1;
    if (s[0] == expected) {
        return offset;
    }
    switch (s[0]) {
        case '(': {
            offset += match(s + offset, ')');
            break;
        }
        case '[': {
            offset += match(s + offset, ']');
            break;
        }
        case '{': {
            offset += match(s + offset, '}');
            break;
        }
        case '<': {
            offset += match(s + offset, '>');
            break;
        }
        default: {
            // I think no offset can be positive after adding this
            return INT32_MIN;
        }
    }
    if (offset < 0) {
        return INT32_MIN;
    } else {
        return offset + match(s + offset, expected);
    }
}
int32_t main(void) {
    char s[LEN];
    for (int32_t i = 0; i < COUNT; i++) {
        scanf("%s", s);
        if (match(s, '\0') <= 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
