// 吃饭各有多少人
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

const int32_t MAN_COST = 3;
const int32_t WOMAN_COST = 2;
const int32_t CHILD_COST = 1;
int32_t count(int32_t man, int32_t woman, int32_t child) {
    return man + woman + child;
}

int32_t cost(int32_t man, int32_t woman, int32_t child) {
    return man * MAN_COST + woman * WOMAN_COST + child * CHILD_COST;
}

void sub(int32_t* man, int32_t* woman, int32_t* child) {
    if (*child > 0) {
        *child -= 1;
        *woman += 1;
    } else if (*woman > 0) {
        *man += 1;
        *child = *woman - 1;
        *woman = 0;
    }
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t people, total_cost;
        scanf("%d %d", &people, &total_cost);

        int32_t man = 0;
        int32_t woman = 0;
        int32_t child = people;

        for (; man * MAN_COST < total_cost; sub(&man, &woman, &child)) {
            if (cost(man, woman, child) == total_cost) {
                printf("%d %d %d\n", man, woman, child);
            }
        }
    }
    return 0;
}
