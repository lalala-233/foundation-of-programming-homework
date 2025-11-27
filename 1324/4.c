// 字符串操作员
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    Delete,
    End,
    Get,
    Lengthen,
    Reverse,
} Command;
int32_t min(int32_t left, int32_t right) {
    return left < right ? left : right;
}
int32_t max(int32_t left, int32_t right) {
    return left > right ? left : right;
}
Command parse_command(char command) {
    switch (command) {
        case 'D':
            return Delete;
        case 'E':
            return End;
        case 'L':
            return Lengthen;
        case 'R':
            return Reverse;
        case ' ':
            return Get;
        default:
            // Unreachable
            return End;
    }
}
char* clone(const char* s, int32_t len) {
    char* s_clone = malloc(sizeof(char) * (len + 1));
    sprintf(s_clone, "%s", s);
    return s_clone;
}
void process(const char* s, const int32_t len) {
    char* s_clone = clone(s, len);
    int32_t new_len = len;
    Command command = End;
    while (true) {
        char current = getchar();
        if (command == Get && isspace(current)) {
            free(s_clone);
            s_clone = clone(s, len);
            int32_t new_len = len;
            continue;
        }
        switch (parse_command(command)) {
            case Delete: {
                int32_t length;
                scanf("%" PRIi32, &length);
                // first_right(0..=5) = 2
                // first_right(0..=4) = 2
                // first_right(0..=3) = 1
                // first_right(0..=2) = 1
                // first_right(0..=1) = 0
                int32_t first_right = new_len / 2;
                int32_t copy_end = max(first_right - length, 0);
                char* new = malloc(sizeof(char) * (copy_end + new_len))

                    break;
            }
            case End: {
                return;
            }
            case Get: {
                int32_t index;
                scanf("%" PRIi32, &index);
                printf("%c\n", s_clone[index - 1]);
                break;
            }
            case Lengthen: {
                break;
            }
            case Reverse: {
                break;
            }
        }
    }
    char character = getchar();
}

int32_t main(void) {
    char origin[33 + 1];
    fgets(origin, 33, stdin);
    int32_t len = strlen(origin);
    if (origin[len - 1] == '\n') {
        origin[len - 1] = '\0';
        len--;
    }
    process(origin, len);
}
