// 奇数的和
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t count;
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        int32_t m, n;
        scanf("%d %d", &m, &n);
        getchar();

        // to make m < n
        if (m > n) {
            int32_t temp = m;
            m = n;
            n = temp;
        }

        // to make sure m and n are odd
        m = m % 2 == 0 ? m + 1 : m;
        n = n % 2 == 0 ? n - 1 : n;

        int32_t count_of_odd_number = (n - m) / 2 + 1;
        int32_t result = (m + n) * count_of_odd_number / 2;

        printf("%d\n", result);
    }
    return 0;
}
