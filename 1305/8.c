// N 行直角杨辉三角
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print_triangle(int32_t array[], int32_t line) {
    if (line == 0) {
        return;
    }
    print_triangle(array, line - 1);
    array[line - 1] = 0;
    array[0] = 1;
    for (int i = 0, top_left = 0; i < line; i++) {
        int top = array[i];
        array[i] = top_left + top;
        printf("%" PRIi32 ",", top_left + top);
        top_left = top;
    }
    printf("\n");
}
int32_t main(void) {
    int32_t number;
    scanf("%d", &number);

    if (number <= 0 || number > 20) {
        printf("Input Error\n");
        return 0;
    }
    int32_t array[number];
    print_triangle(array, number);
    return 0;
}
