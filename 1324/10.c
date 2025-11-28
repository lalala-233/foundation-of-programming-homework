// IP 地址判断
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* END_OF_LINE = "End of file\n";
char* read_len(int32_t len) {
    char* s = (char*)malloc(len + 2);
    fgets(s, len + 2, stdin);
    return s;
}
bool is_valid_ipv4(const char* s) {
    int32_t address_count = 0;

    for (int32_t i = 0, digit = -1; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            if (digit == -1) {
                digit = 0;
            }
            digit *= 10;
            digit += s[i] - '0';
            if (digit < 0 || digit > 255) {
                return false;
            }
        } else if (s[i] == '.' || s[i] == '\n') {
            if (digit < 0 || digit > 255) {
                return false;
            }
            digit = -1;
            address_count++;
        } else {
            return false;
        }
    }
    return address_count == 4;
}
int32_t main(void) {
    while (true) {
        int32_t len = 30;
        char* s = read_len(len);
        if (strcmp(s, END_OF_LINE) == 0) {
            break;
        }
        if (is_valid_ipv4(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        free(s);
    }
}
