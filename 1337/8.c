// 新报数游戏 2
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
bool contains_seven(int32_t number) {
    bool contains_seven = number % 7 == 0;
    while (number != 0 && !contains_seven) {
        contains_seven = number % 10 == 7;
        number /= 10;
    }
    return contains_seven;
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%" PRIi32, &number);

        int32_t alive = number;
        int32_t* players = malloc(sizeof(int32_t) * number);
        for (int32_t j = 0; j < number; j++) {
            players[j] = (j + 1) % number;
        }

        int32_t current = 0;
        for (int32_t counter = 0; alive > 1; counter++) {
            int32_t next = players[current];
            // current_shout = counter + 1
            // next_person_shout = current_shout + 1
            while (alive > 1 && contains_seven(counter + 2)) {
                next = players[next];
                counter++;
                alive--;
            }
            players[current] = next;
            current = next;
        }
        printf("%" PRIi32 "\n", current + 1);
    }
}
