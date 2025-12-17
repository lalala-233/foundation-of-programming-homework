// 成绩排名
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN (10 + 1)
#define ID_LEN (18 + 1)
void read_string(char* name) {
    char current = getchar();
    while (isspace(current)) {
        current = getchar();
    }
    int32_t len = 0;
    while (!isspace(current)) {
        name[len] = current;
        len++;
        current = getchar();
    }
    name[len] = '\0';
}
int32_t read_score() {
    char current = getchar();
    while (isspace(current)) {
        current = getchar();
    }
    if (current == 'n') {
        while (!isspace(current)) {
            current = getchar();
        }
        return -1;
    } else {
        int32_t result = 0;
        while (isdigit(current)) {
            result *= 10;
            result += current - '0';
            current = getchar();
        }
        return result;
    }
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    char* max_score_name = NULL;
    char* max_score_id = NULL;
    int32_t max_score = INT32_MIN;

    char* min_score_name = NULL;
    char* min_score_id = NULL;
    int32_t min_score = INT32_MAX;
    for (int32_t i = 0; i < count; i++) {
        char* name = malloc(sizeof(char) * NAME_LEN);
        read_string(name);
        char* id = malloc(sizeof(char) * ID_LEN);
        read_string(id);
        int32_t score = read_score();
        if (score == -1) {
            goto free_resource;
        }
        if (score < min_score || (score == min_score && strcmp(min_score_name, name) < 0)) {
            min_score = score;
            if (max_score_name != min_score_name) {
                free(min_score_name);
            }
            if (max_score_id != min_score_id) {
                free(min_score_id);
            }
            min_score_name = name;
            min_score_id = id;
        }
        if (score > max_score || (score == max_score && strcmp(max_score_name, name) > 0)) {
            max_score = score;
            if (max_score_name != min_score_name) {
                free(max_score_name);
            }
            if (max_score_id != min_score_id) {
                free(max_score_id);
            }
            max_score_name = name;
            max_score_id = id;
        }
    free_resource:
        if (min_score_name != name && max_score_name != name) {
            free(name);
        }
        if (min_score_id != id && max_score_id != id) {
            free(id);
        }
    }
    printf("%s %s\n", max_score_name, max_score_id);
    printf("%s %s\n", min_score_name, min_score_id);
    return 0;
}
