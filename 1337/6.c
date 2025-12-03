// 找子串
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t is_substr(const char* origin, const char* sub_str) {
    for (int32_t i = 0;; i++) {
        if (sub_str[i] == '\0') {
            return i;
        } else if (origin[i] == '\0') {
            break;
        } else if (tolower(sub_str[i]) == tolower(origin[i])) {
            continue;
        } else {
            break;
        }
    }
    return -1;
}
void read_string(char* s) {
    char current = getchar();
    for (int32_t i = 0;; i++) {
        s[i] = current;
        if (current == '\n') {
            s[i] = '\0';
            break;
        }
        current = getchar();
    }
}
int32_t main(void) {
    char origin[1000 + 1];
    read_string(origin);
    char substr[100 + 1];
    read_string(substr);
    for (int32_t i = 0; origin[i] != '\0';) {
        int32_t skip = is_substr(&origin[i], substr);
        if (skip == -1) {
            printf("%c", origin[i]);
            i++;
            continue;
        }
        printf("/*");
        for (int32_t j = 0; j < skip; j++) {
            printf("%c", origin[i]);
            i++;
        }
        printf("*/");
    }
    printf("\n");
    return 0;
}
