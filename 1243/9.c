// 计算立方和
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t number_1, number_2, number_3;
    scanf("%d %d %d", &number_1, &number_2, &number_3);
    int32_t cube = 0;

    cube += number_1 * number_1 * number_1;
    cube += number_2 * number_2 * number_2;
    cube += number_3 * number_3 * number_3;
    
    printf("%d\n", cube);
    return 0;
}