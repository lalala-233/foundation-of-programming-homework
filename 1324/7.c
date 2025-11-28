// 子串跨度
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_len(int32_t* len) {
    char* s = (char*)malloc(*len + 2);
    fgets(s, *len + 2, stdin);
    *len = strlen(s);
    if (s[*len - 1] == '\n') {
        s[*len - 1] = '\0';
        *len -= 1;
    }
    return s;
}
int32_t main(void) {
    int32_t s_len = 300;
    char* s = read_len(&s_len);
    int32_t left_len = 10;
    char* left_s = read_len(&left_len);
    int32_t right_len = 10;
    char* right_s = read_len(&left_len);

    free(s);
    free(left_s);
    free(right_s);
    return 0;
}
