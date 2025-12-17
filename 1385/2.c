// 查找成绩
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN (10 + 1)
#define ID_LEN (18 + 1)
#define SCORE_LEN (3 + 1)
int32_t read_string(char* name) {
    char current = getchar();
    while (isspace(current)) {
        current = getchar();
    }
    int32_t len = 0;
    while (!isspace(current) && current != EOF) {
        name[len] = current;
        len++;
        current = getchar();
    }
    name[len] = '\0';
    return len;
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    char search[ID_LEN];
    int32_t search_len = read_string(search);
    // bool should_fuzzy = true;
    // if (search_len == 3) {
    //     if (strcmp(search, "n/a") == 0 || strcmp(search, "100") == 0) {
    //         should_fuzzy = false;
    //     }
    // } else if (search_len < 3) {
    //     bool all_digits = true;
    //     for (int32_t i = 0; i < search_len; i++) {
    //         all_digits = all_digits && isdigit(search[i]);
    //     }
    //     if (all_digits) {
    //         should_fuzzy = false;
    //     }
    // }
    for (int32_t i = 0; i < count; i++) {
        char* name = malloc(sizeof(char) * NAME_LEN);
        read_string(name);
        char* id = malloc(sizeof(char) * ID_LEN);
        read_string(id);
        char* score = malloc(sizeof(char) * SCORE_LEN);
        read_string(score);
        if (strstr(name, search) || strstr(id, search)) {
            printf("%s %s %s\n", name, id, score);
        } else if (strcmp(score, search) == 0) {
            printf("%s %s %s\n", name, id, score);
        }
        free(name);
        free(id);
        free(score);
    }
    return 0;
}
