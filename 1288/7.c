// 递归实现逆序输出字符串
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void reverse_print() {
    char character = getchar();
    if (character != '\n') {
        reverse_print();
        printf("%c", character);
    }
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);
    char _new_line = getchar();

    for (int32_t i = 0; i < count; i++) {
        reverse_print();
        printf("\n");
    }
    return 0;
}
