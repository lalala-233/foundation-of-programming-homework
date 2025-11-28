// 比较两个整数大小
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUMBER "1000000000000000000000000000000"
#define MAX_LEN sizeof(MAX_NUMBER) - 1
char* read_len(int32_t* len, int32_t* offset) {
    char* s = (char*)malloc(2 * MAX_LEN);
    bool is_valid_number = true;
    do {
        s[0] = getchar();
    } while (isspace(s[0]));
    if (!isdigit(s[0])) {
        is_valid_number = false;
    }
    for (int32_t i = 1; i < 2 * MAX_LEN; i++) {
        s[i] = getchar();
        if (isspace(s[i])) {
            s[i] = '\0';
            *len = i;
            break;
        }
        // reading until a space is encountered
        // although there is a non-digit
        if (!isdigit(s[i])) {
            is_valid_number = false;
        }
    }
    *offset = 0;
    while (s[*offset] == '0' && *offset < *len - 1) {
        *offset += 1;
    }
    *len -= *offset;
    if (*len == MAX_LEN) {
        int32_t result = strcmp(s + *offset, MAX_NUMBER);
        is_valid_number = is_valid_number && (result == 0);
    }
    if (is_valid_number) {
        return s;
    } else {
        free(s);
        return NULL;
    }
}

int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);

    char* left_s = NULL;
    char* right_s = NULL;
    for (int32_t i = 0; i < count; i++) {
        free(left_s);
        free(right_s);
        left_s = NULL;
        right_s = NULL;

        int32_t left_len, left_offset;
        left_s = read_len(&left_len, &left_offset);

        int32_t right_len, right_offset;
        right_s = read_len(&right_len, &right_offset);

        // printf("left: %s\nright: %s\n", left_s, right_s);
        if (left_s == NULL || right_s == NULL) {
            printf("Input Error\n");
            continue;
        }
        if (left_len < right_len) {
            printf("%s\n", left_s + left_offset);
            continue;
        } else if (left_len > right_len) {
            printf("%s\n", right_s + right_offset);
            continue;
        }

        int32_t result = strcmp(left_s + left_offset, right_s + right_offset);
        if (result < 0) {
            printf("%s\n", left_s + left_offset);
        } else if (result > 0) {
            printf("%s\n", right_s + right_offset);
        } else {
            printf("Input Error\n");
        }
    }
    free(left_s);
    free(right_s);
    return 0;
}
