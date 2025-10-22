// 计算分段函数
#include <stdio.h>
int main(void) {
    double x;
    scanf("%lf", &x);

    double y;
    if (x < 0) {
        y = x * x;
    } else if (x <= 10) {
        y = 2 * x + 3;
    } else {
        y = 3 * x - 7;
    }

    printf("%.2f\n", y);

    return 0;
}
