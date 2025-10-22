// 判断字符类型
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
int main(void) {
    int32_t count;
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        char character;
        scanf("%c", &character);
        getchar();

        if (isdigit(character)) {
            printf("number\n");
        } else if (isalpha(character)) {
            printf("letter\n");
        } else {
            printf("else\n");
        }
    }
    return 0;
}
