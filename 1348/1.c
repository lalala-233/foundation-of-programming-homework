// 学号
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t parse_number_tool(int32_t in, int32_t* current) {
    char current_char = getchar();
    if (!isspace(current_char)) {
        int32_t result = parse_number_tool(in, current);
        if (isdigit(current_char)) {
            current_char -= '0';
        } else {
            current_char = current_char - 'A' + 10;
        }
        result += current_char * *current;
        *current *= in;
        return result;
        ;
    } else {
        return 0;
    }
}
int32_t parse_number(int32_t in) {
    int32_t current = 1;
    return parse_number_tool(in, &current);
}
void print(int32_t number, int32_t in) {
    int32_t digit = number % in;
    if (number / in != 0) {
        print(number / in, in);
    }
    if (digit < 10) {
        digit += '0';
    } else {
        digit = digit - 10 + 'A';
    }
    printf("%c", digit);
}
int32_t main(void) {
    int32_t initial;
    scanf("%" PRIi32, &initial);
    char _new_line = getchar();

    int32_t number_in_ten = parse_number(initial);

    int32_t target;
    scanf("%" PRIi32, &target);

    print(number_in_ten, target);
    printf("\n");
    return 0;
}
