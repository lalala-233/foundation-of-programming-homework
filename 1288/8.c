// 统计星号
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum { Asterisk, Count, Skip } Status;

Status count(int32_t character) {
    if (character == '|') {
        return Skip;
    }
    if (character == '*') {
        return Asterisk;
    }
    return Count;
}

Status skip(int32_t character) {
    if (character == '|') {
        return Count;
    }
    return Skip;
}

int32_t main(void) {
    int32_t result = 0;
    int32_t character = getchar();
    Status status = Count;
    while (character != EOF) {
        if (status == Asterisk) {
            result++;
            status = count(character);
        } else if (status == Count) {
            status = count(character);
        } else {
            status = skip(character);
        }
        character = getchar();
    }
    printf("%d\n", result);
    return 0;
}
