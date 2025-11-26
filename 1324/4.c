// 字符串操作员
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char* inner;
    int32_t start;
    int32_t end;
    bool is_forward;
} String;
typedef enum {
    Delete,
    End,
    Get,
    Lengthen,
    Reverse,
} CommandEnum;
int32_t min(int32_t left, int32_t right) {
    return left < right ? left : right;
}
int32_t max(int32_t left, int32_t right) {
    return left > right ? left : right;
}
void debug(String s) {
    int32_t step = 1;
    int32_t start = s.start;
    int32_t end = s.end;
    if (!s.is_forward) {
        step = -1;
        start = s.end;
        end = s.start;
    }
    for (int32_t i = start; i != end; i += step) {
        putchar(s.inner[i]);
    }
    putchar(s.inner[end]);
    putchar('\n');
}
void free_string(String s) {
    free(s.inner);
}
String reverse(String s) {
    s.is_forward = !s.is_forward;
    return s;
}
String delete(String s, int32_t number) {
    // Example:
    // max_difference(0..=3) = 2 = (3 + 1) / 2
    // max_difference(0..=4) = 2 = (4 + 1) / 2
    // max_difference(1..=3) = 1 = (2 + 1) / 2
    // max_difference(1..=4) = 2 = (3 + 1) / 2
    int32_t max_difference = (s.end - s.start + 1) / 2;
    int32_t difference = min(number, max_difference);
    if (s.is_forward) {
        s.start += difference;
    } else {
        s.end -= difference;
    }
    return s;
}
String lengthen(String s) {
    char* inner = malloc(sizeof(char) * (s.end - s.start + 1) * 2);
    int32_t index = 0;
    for (int32_t i = s.start; i <= s.end; i++) {
        inner[index] = s.inner[i];
        inner[index + 1] = s.inner[i];
        index += 2;
    }
    free_string(s);
    String result = {inner, 0, index - 1, s.is_forward};
    return result;
}
bool index_in_boundary(String s, int32_t index) {
    return (s.start + index) <= s.end;
}
char get_unchecked(String s, int32_t index) {
    if (s.is_forward) {
        return s.inner[s.start + index];
    } else {
        return s.inner[s.end - index];
    }
}
String clone(String s) {
    char* inner = malloc(sizeof(char) * (s.end - s.start + 1));
    int32_t index = 0;
    for (int32_t i = s.start; i <= s.end; i++) {
        inner[index] = s.inner[i];
        index++;
    }
    String result = {inner, 0, index - 1, s.is_forward};
    return result;
}
String new(char* inner) {
    int32_t end = strlen(inner) - 1;
    while (isspace(inner[end])) {
        end--;
    }
    String result = {inner, 0, end, true};
    return result;
}
CommandEnum parse_command(char command) {
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
void process(String s) {
    String s_clone = clone(s);
    CommandEnum command = End;
    while (true) {
        char current = getchar();
        if (command == Get && isspace(current)) {
            free_string(s_clone);
            s_clone = clone(s);
            continue;
        }
        command = parse_command(current);
        switch (command) {
            case Delete: {
                int32_t value;
                scanf("%" PRIi32, &value);
                s_clone = delete(s_clone, value);
                break;
            }
            case End: {
                free_string(s_clone);
                free_string(s);
                return;
            }
            case Get: {
                int32_t index;
                scanf("%" PRIi32, &index);
                index -= 1;
                if (index_in_boundary(s_clone, index) && index >= 0) {
                    char c = get_unchecked(s_clone, index);
                    printf("%c\n", c);
                } else {
                    printf("NULL\n");
                }
                break;
            }
            case Lengthen: {
                s_clone = lengthen(s_clone);
                break;
            }
            case Reverse: {
                s_clone = reverse(s_clone);
                break;
            }
        }
        // printf("current: %c, s: ", current);
        // debug(s_clone);
    }
}
int32_t main(void) {
    char* origin = malloc(sizeof(char) * (32 + 1));
    fgets(origin, 32, stdin);
    String s = new(origin);
    process(s);
}