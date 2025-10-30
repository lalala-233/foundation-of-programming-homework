// 统计元音字母
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main(void) {
    char s[1001];
    fgets(s, 1001, stdin);
    int32_t result = 0;

    for (int32_t i = 0, len = strlen(s); i < len; i++) {
        char character = tolower(s[i]);
        switch (character) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': {
                result++;
                printf("%c-", character);
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
