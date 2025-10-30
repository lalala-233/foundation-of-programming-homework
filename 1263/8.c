// 去除空白
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum { Letter, NeedWhitespace, End, NoNeedWhitespace } Status;

Status process(Status current_status, int32_t current_character) {
    if (current_character == EOF) {
        return End;
    } else if (isspace(current_character)) {
        return (current_status == Letter) ? NeedWhitespace : current_status;
    } else {
        if (current_status == NeedWhitespace) {
            printf(" ");
        }
        printf("%c", current_character);
        return Letter;
    }
}

int32_t main(void) {
    Status current_status = NoNeedWhitespace;
    int32_t character;
    while (current_status != End) {
        character = getchar();
        current_status = process(current_status, character);
    }
    printf("\n");

    return 0;
}
