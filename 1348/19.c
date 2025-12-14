// 土豪
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t main(void) {
    int32_t number_count;
    scanf("%" PRIi32, &number_count);
    int32_t search;
    scanf("%" PRIi32, &search);

    int32_t buffer[search];
    int32_t index_buffer[search];
    int32_t head = 0;
    int32_t tail = 0;
    for (int32_t i = 0; i < number_count; i++) {
        scanf("%" PRIi32, &buffer[i % search]);
        if (head < tail) {
            int32_t before_index = index_buffer[head % search];
            if (i - before_index >= search) {
                head++;
            }
        }

        while (head != tail) {
            int32_t tail_index = index_buffer[(tail - 1) % search];
            if (buffer[i % search] > buffer[tail_index % search]) {
                tail--;
            } else {
                break;
            }
        }
        index_buffer[tail % search] = i;
        tail++;

        if (i >= search - 1) {
            int32_t head_index = index_buffer[head % search];
            printf("%" PRIi32, buffer[head_index % search]);
            if (i != number_count - 1) {
                putchar(' ');
            } else {
                putchar('\n');
            }
        }
    }

    return 0;
}
