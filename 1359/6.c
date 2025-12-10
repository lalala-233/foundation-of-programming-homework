// 子串消消乐
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN (1000 + 1)
int32_t substr_length(const char* origin, const char* sub_str) {
    for (int32_t i = 0;; i++) {
        if (sub_str[i] == '\0') {
            return i;
        } else if (origin[i] == '\0') {
            break;
        } else if (sub_str[i] == origin[i]) {
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
    char* sentence = malloc(sizeof(char) * LEN);
    read_string(sentence);

    char* search = malloc(sizeof(char) * (10 + 1));
    read_string(search);

    bool str_is_null = true;
    for (int32_t i = 0; sentence[i] != '\0'; i++) {
        int32_t length = substr_length(&sentence[i], search);
        if (length == -1) {
            str_is_null = false;
            printf("%c", sentence[i]);
            continue;
        }
        i += length - 1;
    }
    if (str_is_null) {
        printf("null");
    }
    printf("\n");
    return 0;
}
