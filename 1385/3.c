// 查找成绩排名
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN (10 + 1)
#define ID_LEN (18 + 1)
#define SCORE_LEN (3 + 1)
void read_string(char* name) {
    char current = getchar();
    while (isspace(current)) {
        current = getchar();
    }
    int32_t len = 0;
    while (!isspace(current) && current != EOF) {
        name[len] = current;
        len++;
        current = getchar();
    }
    name[len] = '\0';
}
typedef struct {
    char* name;
    char* id;
    char* score;
} Student;
int32_t cmp(const void* student_1, const void* student_2) {
    Student student_1_ = *(Student*)student_1;
    Student student_2_ = *(Student*)student_2;
    int32_t score_1;
    int32_t score_2;
    if (strcmp(student_1_.score, "n/a") == 0) {
        score_1 = -1;
    } else {
        score_1 = atoi(student_1_.score);
    }
    if (strcmp(student_2_.score, "n/a") == 0) {
        score_2 = -1;
    } else {
        score_2 = atoi(student_2_.score);
    }
    return score_2 - score_1;
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    char search[ID_LEN];
    read_string(search);
    Student students[count];
    for (int32_t i = 0; i < count; i++) {
        students[i].name = malloc(sizeof(char) * NAME_LEN);
        read_string(students[i].name);
        students[i].id = malloc(sizeof(char) * ID_LEN);
        read_string(students[i].id);
        students[i].score = malloc(sizeof(char) * SCORE_LEN);
        read_string(students[i].score);
    }
    qsort(students, count, sizeof(Student), cmp);

    for (int32_t i = 0, rank = i + 1; i < count; i++) {
        if (i > 0 && strcmp(students[i].score, students[i - 1].score) != 0) {
            rank = i + 1;
        }
        if (strstr(students[i].id, search) || strstr(students[i].name, search)) {
            printf("%s %s %s ", students[i].name, students[i].id, students[i].score);
            if (strcmp(students[i].score, "n/a") == 0) {
                printf("n/a\n");
            } else {
                printf("%" PRIi32 "\n", rank);
            }
        } else if (strcmp(students[i].score, search) == 0) {
            printf("%s %s %s", students[i].name, students[i].id, students[i].score);
            if (strcmp(students[i].score, "n/a") == 0) {
                printf("n/a\n");
            } else {
                printf("%" PRIi32 "\n", rank);
            }
        }
    }
    for (int32_t i = 0; i < count; i++) {
        free(students[i].name);
        free(students[i].id);
        free(students[i].score);
    }
    return 0;
}
