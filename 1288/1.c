// 找出丢失的数
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        bool array[1001] = {false};
        while (true) {
            int32_t number;
            scanf("%d", &number);
            array[number] = true;
            if (number == 0) {
                break;
            }
        }
        for (int32_t j = 0; j <= 1001; j++) {
            if (array[j] == false) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}
