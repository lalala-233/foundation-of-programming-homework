// 温度转换
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t fahrenheit;
    scanf("%d", &fahrenheit);

    if (fahrenheit <= 0) {
        printf("error\n");
        return 0;
    }

    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f\n", celsius);
    return 0;
}