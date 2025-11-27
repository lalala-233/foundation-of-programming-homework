// 报数游戏
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        int32_t alive = number;
        int32_t* players = malloc(sizeof(int32_t) * number);
        for (int32_t j = 0; j < number; j++) {
            players[j] = j + 1;
        }
        players[number - 1] = 0;

        int32_t current = 0;
        for (bool should_skip_next = false; alive != 1;) {
            // should_skip_next, current, players[current]
            // 0, 0, 1
            // 1, 1, 2 -> 3
            // 0, 3, 4
            // 1, 4, 5 -> 6
            if (should_skip_next) {
                int32_t next = players[current];
                players[current] = players[next];
                alive--;
            }
            should_skip_next = !should_skip_next;
            current = players[current];
        }
        printf("%d\n", current + 1);
        free(players);
    }
    return 0;
}
