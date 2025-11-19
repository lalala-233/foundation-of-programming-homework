// 只出现 2 次的数
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    int32_t number;
    int32_t count;
} NumberCount;

void insert(NumberCount array[20], int32_t* size, int32_t number) {
    for (int32_t i = 0; i < *size; i++) {
        if (array[i].number == number) {
            array[i].count++;
            return;
        }
    }
    array[*size].number = number;
    array[*size].count = 1;
    *size += 1;
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    NumberCount array[20];
    int32_t size = 0;
    int32_t number;
    for (int32_t i = 0; i < count; i++) {
        scanf("%d", &number);
        insert(array, &size, number);
    }
    bool have_solution = false;
    for (int32_t i = 0; i < size; i++) {
        if (array[i].count == 2) {
            if (have_solution) {
                printf(" ");
            }
            printf("%d", array[i].number);
            have_solution = true;
        }
    }
    if (!have_solution) {
        printf("none");
    }
    printf("\n");
    return 0;
}
