// 子串跨度
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
char* read_len(int32_t* len) {
    char* s = (char*)malloc(*len + 1);
    for (int32_t i = 0;; i++) {
        s[i] = getchar();
        if (isspace(s[i])) {
            s[i] = '\0';
            *len = i;
            break;
        }
    }
    return s;
}
bool is_substr(const char* origin, const char* substr) {
    for (int32_t i = 0;; i++) {
        if (substr[i] == '\0') {
            return true;
        } else if (origin[i] == '\0') {
            return false;
        } else if (origin[i] != substr[i]) {
            return false;
        }
    }
}
int32_t find_left_start(const char* origin, const char* substr, int32_t count) {
    return -1;
}
int32_t main(void) {
    int32_t s_len = 300;
    char* s = read_len(&s_len);
    int32_t left_len = 10;
    char* left_s = read_len(&left_len);
    int32_t right_len = 10;
    char* right_s = read_len(&right_len);

    int32_t left_start = -1;
    for (int32_t i = 0, search_end = s_len - left_len - right_len; i <= search_end; i++) {
        if (is_substr(&s[i], left_s)) {
            left_start = i;
            break;
        }
    }
    if (left_start == -1) {
        printf("-1\n");
        return 0;
    }

    int32_t right_start = -1;
    for (int32_t i = s_len - right_len, rsearch_end = left_start + left_len; i >= rsearch_end; i--)
    {
        if (is_substr(&s[i], right_s)) {
            right_start = i;
            break;
        }
    }
    if (right_start == -1) {
        printf("-1\n");
        return 0;
    }
    printf("%" PRIi32 "\n", right_start - left_start - left_len);

    free(s);
    free(left_s);
    free(right_s);
    return 0;
}
