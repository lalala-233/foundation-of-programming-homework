// 最长相同后缀
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define LEN (1000 + 1)

int32_t main(void) {
    char str_1[LEN];
    char str_2[LEN];
    fgets(str_1, sizeof(str_1), stdin);
    fgets(str_2, sizeof(str_2), stdin);

    // fgets will get `\n`, - 1
    // as a index, you must - 1
    int32_t len_1 = strlen(str_1) - 2;
    int32_t len_2 = strlen(str_2) - 2;

    if (str_1[len_1] != str_2[len_2]) {
        printf("null\n");
        return 0;
    }
    int32_t start = len_1;
    for (int32_t i = 1;; i++) {
        int32_t index_1 = len_1 - i;
        int32_t index_2 = len_2 - i;
        if (index_1 < 0 || index_2 < 0) {
            break;
        } else if (str_1[index_1] == str_2[index_2]) {
            start--;
        } else {
            break;
        }
    }
    // don't need `\n' because fgets provide a `\n`
    printf("%s", &str_1[start]);
    return 0;
}
