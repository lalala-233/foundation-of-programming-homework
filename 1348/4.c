// 废话
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t main(void) {
    int32_t counts[10 + 26] = {0};
    int32_t max_count = 0;
    char current = getchar();
    while (current != '\n') {
        if (isdigit(current)) {
            current -= '0';
        } else if (isalpha(current)) {
            current = toupper(current);
            current = current - 'A' + 10;
        } else {
            current = getchar();
            continue;
        }
        counts[current] += 1;
        max_count = max_count > counts[current] ? max_count : counts[current];
        current = getchar();
    }

    while (max_count > 0) {
        for (int32_t i = 0; i < 10 + 26; i++) {
            if (counts[i] < max_count) {
                printf("-");
            } else {
                printf("*");
            }
            if (i + 1 == 10 + 26) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
        max_count--;
    }

    for (int32_t i = 0; i < 10 + 26; i++) {
        if (i < 10) {
            printf("%" PRIi32, i);
        } else {
            printf("%c", i - 10 + 'A');
        }
        if (i + 1 == 10 + 26) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}
