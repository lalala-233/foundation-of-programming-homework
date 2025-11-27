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
    int32_t str_len = len;
    Command command = Get;
    while (true) {
        char current = getchar();
        if (command == Get && isspace(current)) {
            free(s_clone);
            s_clone = clone(s, len);
            str_len = len;
            continue;
        }
        command = parse_command(current);
        switch (command) {
            case Delete: {
                int32_t delete_length;
                scanf("%" PRIi32, &delete_length);
                // first_right(0..=5) = 2
                // first_right(0..=4) = 2
                // first_right(0..=3) = 1
                // first_right(0..=2) = 1
                // first_right(0..=1) = 0
                int32_t first_right = str_len / 2;

                int32_t new_len = str_len - min(first_right, delete_length);
                char* new = malloc(sizeof(char) * (new_len + 1));

                int32_t copy_end = max(first_right - delete_length, 0);
                int32_t index = 0;
                for (; index < copy_end; index++) {
                    new[index] = s_clone[index];
                }
                for (int32_t j = 0; index < new_len; j++) {
                    new[index] = s_clone[j + first_right];
                    index++;
                }
                new[index] = '\0';

                free(s_clone);
                s_clone = new;
                str_len = new_len;
                break;
            }
            case End: {
                free(s_clone);
                return;
            }
            case Get: {
                int32_t index;
                scanf("%" PRIi32, &index);
                if (index > str_len || index < 1) {
                    printf("NULL\n");
                } else {
                    printf("%c\n", s_clone[index - 1]);
                }
                break;
            }
            case Lengthen: {
                int32_t new_len = str_len * 2;
                char* new = malloc(sizeof(char) * (new_len + 1));
                for (int32_t i = 0; i < str_len; i++) {
                    new[2 * i] = s_clone[i];
                    new[2 * i + 1] = s_clone[i];
                }
                new[new_len] = '\0';
                free(s_clone);
                s_clone = new;
                str_len = new_len;
                break;
            }
            case Reverse: {
                for (int32_t i = 0; i < str_len / 2; i++) {
                    char temp = s_clone[i];
                    s_clone[i] = s_clone[str_len - i - 1];
                    s_clone[str_len - i - 1] = temp;
                }
                break;
            }
        }
        // printf("command: %c, current: %s\n", current, s_clone);
    }
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
    return 0;
}
