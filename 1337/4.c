// 单词逆序
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
void print_reverse_word(const char* s) {
    if (s[0] == '\0') {
        return;
    }
    int32_t next_start = 0;
    while (isalpha(s[next_start])) {
        next_start++;
    }
    for (int32_t i = next_start - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    if (next_start == 0) {
        printf("%c", s[next_start]);
        next_start++;
    }
    const char* next_start_s = &s[next_start];
    print_reverse_word(next_start_s);
}

int32_t main(void) {
    char s[1000 + 1];
    fgets(s, 1000, stdin);
    print_reverse_word(s);
    return 0;
}
