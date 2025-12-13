// 朋友
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef enum { Build, Query } Command;
Command parse(int32_t command) {
    switch (command) {
        case 1: {
            return Build;
        }
        case 2: {
            return Query;
        }
    }
    // unreachable
    return Query;
}
int32_t get_root(int32_t* root, int32_t self) {
    if (root[self] != self) {
        root[self] = get_root(root, root[self]);
    }
    return root[self];
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    int32_t length;
    scanf("%" PRIi32, &length);
    int32_t* rank = calloc(length, sizeof(int32_t));
    int32_t* root = malloc(sizeof(int32_t) * length);
    for (int32_t i = 0; i < length; i++) {
        root[i] = i;
    }

    for (int32_t i = 0; i < count; i++) {
        int32_t command_int;
        scanf("%" PRIi32, &command_int);
        Command command = parse(command_int);
        int32_t x, y;
        scanf("%" PRIi32, &x);
        scanf("%" PRIi32, &y);
        x -= 1;
        y -= 1;
        switch (command) {
            case Build: {
                int32_t root_x = get_root(root, x);
                int32_t root_y = get_root(root, y);
                if (root_x == root_y) {
                    continue;
                }

                if (rank[root_x] < rank[root_y]) {
                    root[root_x] = root_y;
                } else if (rank[root_x] > rank[root_y]) {
                    root[root_y] = root_x;
                } else {
                    root[root_y] = root_x;
                    rank[root_x] += 1;
                }
                break;
            }
            case Query: {
                if (get_root(root, x) == get_root(root, y)) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
                break;
            }
        }
    }
    free(rank);
    free(root);
    return 0;
}
