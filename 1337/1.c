// 子序列个数
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN (1000 + 1)
char* get_str() {
    char* s = (char*)malloc(LEN);
    for (int32_t i = 0;; i++) {
        s[i] = getchar();
        if (isspace(s[i])) {
            s[i] = '\0';
            break;
        }
    }
    return s;
}
int32_t main(void) {
    char* origin_str = get_str();
    char* sub_str = get_str();
    int32_t sub_str_count = 0;
    char* search_result = strstr(origin_str, sub_str);
    while (search_result != NULL) {
        sub_str_count++;
        search_result = strstr(search_result + 1, sub_str);
    }
    printf("%" PRIi32 "\n", sub_str_count);
    free(origin_str);
    free(sub_str);
    return 0;
}
