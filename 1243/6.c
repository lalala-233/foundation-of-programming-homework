// 计算圆柱体的体积和表面积
#include <stdio.h>

int main(void) {
    const double PI = 3.14159;
    double radius, height;
    scanf("%lf %lf", &radius, &height);

    double volume = PI * radius * radius * height;
    double area = 2 * PI * radius * (radius + height);

    printf("%.2f %.2f\n", volume, area);

    return 0;
}