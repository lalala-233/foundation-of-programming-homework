// 字符串操作员
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
typedef struct {
    char* s;
    int32_t len;
    // start depends on is_forward
    int32_t start;
    bool is_forward;
} String;
typedef enum {
    Lengthen,
    Reverse,
    Delete,
} CommandEnum;
typedef struct {
    CommandEnum type;
    int32_t value;
} Command;
int32_t min(int32_t left, int32_t right) {
    return left < right ? left : right;
}
int32_t max(int32_t left, int32_t right) {
    return left > right ? left : right;
}
String reverse(String s) {
    s.is_forward = !s.is_forward;
    return s;
}
String delete(String s, int32_t number) {
    // Example:
    // middle(0..3) = 3 / 2 + 1 = 2
    // middle(0..4) = 4 / 2 + 1 = 3
    // middle(0..5) = 5 / 2 + 1 = 3
    int32_t middle = (s.start + s.len) / 2 + 1;
    int32_t difference = min(number, middle - s.start);
    if (s.is_forward) {
        s.start = ;
        s.len = s.len - s.start;
    } else {
        s.start = min(s.start - number, middle);
    }
}
int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a >= b) {
            int32_t tmp = a;
            a = b;
            b = tmp;
        }
        if (b >= c) {
            int32_t tmp = b;
            b = c;
            c = tmp;
        }
        if (a >= b) {
            int32_t tmp = a;
            a = b;
            b = tmp;
        }

        if (a + b <= c) {
            printf("No\n");
        } else if (a * a + b * b == c * c) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
