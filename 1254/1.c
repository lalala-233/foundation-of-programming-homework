// 最大值和最小值的差
#include <stdint.h>
#include <stdio.h>
int min(int number_1, int number_2) {
    return number_1 > number_2 ? number_2 : number_1;
}
int max(int number_1, int number_2) {
    return number_1 > number_2 ? number_1 : number_2;
}
int main(void) {
    int32_t number_1, number_2, number_3;
    scanf("%d %d %d", &number_1, &number_2, &number_3);

    int32_t min_number = min(min(number_1, number_2), number_3);
    int32_t max_number = max(max(number_1, number_2), number_3);

    printf("%d\n", max_number - min_number);

    return 0;
}
