// 提取指定的位
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t num, place;
    scanf("%d %d", &num, &place);

    int32_t result;

    if (place > 0 && place <= 3 && num >= 100 && num < 1000) {
        switch (place) {
            case 1:
                result = num % 10;
                break;
            case 2:
                result = (num / 10) % 10;
                break;
            case 3:
                result = (num / 100) % 10;
                break;
        }
        printf("%d\n", result);
    } else {
        printf("illegal\n");
    }

    return 0;
}