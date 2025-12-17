// 最多的单词
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN (50 + 1)
#define LEN 10000
bool read_string(char* name) {
    char current = getchar();
    while (!isalpha(current) && current != EOF) {
        current = getchar();
    }
    int32_t len = 0;
    while (isalpha(current)) {
        name[len] = tolower(current);
        len++;
        current = getchar();
    }
    name[len] = '\0';
    return len > 0;
}
typedef struct {
    char* word;
    int32_t count;
} Pair;
int32_t cmp(const void* pair_1, const void* pair_2) {
    Pair pair_1_ = *(Pair*)pair_1;
    Pair pair_2_ = *(Pair*)pair_2;
    if (pair_1_.count != pair_2_.count) {
        return pair_2_.count - pair_1_.count;
    } else {
        return strcmp(pair_2_.word, pair_1_.word);
    }
}
int32_t main(void) {
    Pair pairs[LEN];
    int32_t len = 0;
    while (true) {
        char* word = malloc(STR_LEN * sizeof(char));
        if (read_string(word) == false) {
            free(word);
            break;
        }
        bool found_name = false;
        for (int32_t i = 0; i < len; i++) {
            if (strcmp(pairs[i].word, word) == 0) {
                pairs[i].count++;
                free(word);
                found_name = true;
                break;
            }
        }
        if (!found_name) {
            pairs[len].word = word;
            pairs[len].count = 1;
            len++;
        }
    }
    // Actually we don't need to sort the array,
    // but we don't care

    qsort(pairs, len, sizeof(Pair), cmp);
    printf("%s %" PRIi32 "\n", pairs[0].word, pairs[0].count);
    return 0;
}
