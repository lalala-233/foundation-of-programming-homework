// 链表去重
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    char id[20];
} Student;
void read_string(char* s) {
    int32_t current = getchar();
    while (isspace(current) && current != EOF) {
        current = getchar();
    }
    int32_t len = 0;
    while (!isspace(current) && current != EOF) {
        s[len] = current;
        len++;
        current = getchar();
    }
    s[len] = '\0';
}
bool is_duplicated(Student* students, int32_t len) {
    for (int32_t i = 0; i < len; i++) {
        if (strcmp(students[i].id, students[len].id) == 0) {
            return true;
        }
    }
    return false;
}
int32_t main(void) {
    int32_t number;
    scanf("%" PRIi32, &number);

    Student* students = malloc(sizeof(Student) * number);
    int32_t len = 0;

    for (int32_t i = 0; i < number; i++) {
        read_string(students[len].name);
        read_string(students[len].id);
        if (!is_duplicated(students, len)) {
            printf("%s %s\n", students[len].name, students[len].id);
            len++;
        }
    }

    free(students);
    return 0;
}
