// 新报数游戏 2
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main(void) {
    int32_t number;
    scanf("%" PRIi32, &number);

    int32_t* players = malloc(sizeof(int32_t) * number);
    for (int32_t j = 0; j < number; j++) {
        players[j] = (j + 1) % number;
    }
    int32_t before = number - 1;
    int32_t current = 0;
    for (int32_t alive = number; alive > 0; alive--) {
        /*
        10: 1 2 (3) 4 5 6 7 8 9 10
        9: 4 5 (6) 7 8 9 10 1 2
        8: 7 8 (9) 10 1 2 4 5 
        7: 10 1 (2) 4 5 7 8 
        6: 4 5 (7) 8 10 1 
        5: 8 10 (1) 4 5 
        4: 4 5 (8) 10 
        3: 10 4 (5) 
        2: 10 4 (10)
        1: 4 4 (4)
        */
        int32_t shout;
        scanf("%" PRIi32, &shout);
        shout = (shout - 1) % alive + 1;
        for (int32_t i = 1; i < shout; i++) {
            // printf("\nbefore: %" PRIi32, before + 1);
            // printf(" current: %" PRIi32 "\n", current + 1);
            before = current;
            current = players[current];
        }
        printf("%" PRIi32, current + 1);
        current = players[current];
        players[before] = current;
        if (alive > 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    free(players);
}
