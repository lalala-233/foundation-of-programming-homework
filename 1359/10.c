// 删除注释
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN 100
bool print(const char* s, int32_t from, int32_t to) {
    bool print_yet = false;
    for (int32_t i = from; i < to; i++) {
        print_yet = true;
        putchar(s[i]);
    }
    return print_yet;
}
void process(const char* s) {
    bool encounter_comment = false;
    bool encounter_parenthesis = false;
    bool print_yet = false;
    for (int32_t i = 0, from = 0;;) {
        if (s[i] == '\n') {
            print_yet = print(s, from, i) || print_yet;
            break;
        }

        if (s[i] == '(' && s[i + 1] == '#' && s[i + 2] == '#' && !encounter_comment) {
            i += 3;
            encounter_parenthesis = true;
            encounter_comment = true;
        } else if (s[i] == '#' && s[i + 1] == '#' && s[i + 2] == ')' && encounter_parenthesis) {
            i += 3;
            print_yet = print(s, from, i) || print_yet;
            from = i;
            encounter_parenthesis = false;
            encounter_comment = false;
        } else if (s[i] == '#' && s[i + 1] == '#') {
            i += 2;
            if (encounter_comment) {
                from = i;
                if (encounter_parenthesis) {
                    encounter_parenthesis = false;
                    putchar('(');
                    print_yet = true;
                }
            }
            encounter_comment = !encounter_comment;
        } else if (!encounter_comment) {
            if (from != i) {
                printf("FROM != I\n");
            }
            print_yet = true;
            putchar(s[i]);
            from++;
            i++;
        } else if (encounter_comment) {
            i++;
        } else {
            printf("SOME ERROR\n");
        }
    }
    if (!print_yet) {
        printf("NULL");
    }
    putchar('\n');
}
int32_t main(void) {
    char* s = malloc(sizeof(char) * (LEN + 2));
    fgets(s, LEN, stdin);
    process(s);
    return 0;
}
