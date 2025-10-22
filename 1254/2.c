// 大小写互换和 ASCII 码
#include <ctype.h>
#include <stdio.h>
int main(void) {
    char character;
    scanf("%c", &character);

    if (islower(character)) {
        character = toupper(character);
    } else if (isupper(character)) {
        character = tolower(character);
    }

    printf("%c %d\n", character, character);

    return 0;
}
