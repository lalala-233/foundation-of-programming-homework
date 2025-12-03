// 识别 ISBN 编码
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define ISBN_LENGTH 13
#define ISBN_NORMAL_NUMBER_COUNT 9
int32_t main(void) {
    char isbn[ISBN_LENGTH];
    for (int32_t i = 0; i < ISBN_LENGTH; i++) {
        isbn[i] = getchar();
    }
    int32_t result = 0;
    for (int32_t i = 0, nth = 0; i < ISBN_LENGTH - 1; i++) {
        char current = isbn[i];
        if (!isdigit(current)) {
            continue;
        }
        nth += 1;
        result += nth * (current - '0');
    }
    result %= 11;
    int32_t validated_number = isbn[ISBN_LENGTH - 1];
    if (result == 10) {
        result = 'X';
    } else {
        result += '0';
    }
    if (result == validated_number) {
        printf("Right\n");
    } else {
        isbn[ISBN_LENGTH - 1] = '\0';
        printf("%s%c\n", isbn, result);
    }
    return 0;
}
