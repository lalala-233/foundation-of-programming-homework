// 插队
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct List {
    struct List* previous;
    struct List* next;
    int32_t value;
} List;
typedef enum { PushFront, Push, PopFront, Pop, QueryFront } Command;
Command parse(int32_t command) {
    switch (command) {
        case 1: {
            return Push;
        }
        case 2: {
            return PushFront;
        }
        case 3: {
            return PopFront;
        }
        case 4: {
            return Pop;
        }
        case 5: {
            return QueryFront;
        }
    }
    // unreachable
    return QueryFront;
}

int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);

    List* head = NULL;
    List* tail = NULL;
    for (int32_t i = 0; i < count; i++) {
        int32_t command_int;
        scanf("%" PRIi32, &command_int);
        Command command = parse(command_int);
        switch (command) {
            case Push: {
                int32_t value;
                scanf("%" PRIi32, &value);
                List* new = malloc(sizeof(List));
                new->value = value;

                new->previous = tail;
                new->next = NULL;

                if (tail == NULL) {
                    head = new;
                    tail = new;
                } else {
                    tail->next = new;
                    tail = new;
                }
                break;
            }
            case PushFront: {
                int32_t value;
                scanf("%" PRIi32, &value);
                List* new = malloc(sizeof(List));
                new->value = value;

                new->previous = NULL;
                new->next = head;

                if (head == NULL) {
                    head = new;
                    tail = new;
                } else {
                    head->previous = new;
                    head = new;
                }
                break;
            }
            case PopFront: {
                List* to_delete = head;
                head = head->next;

                if (head == NULL) {
                    tail = NULL;
                } else {
                    head->previous = NULL;
                }

                free(to_delete);
                break;
            }

            case Pop: {
                List* to_delete = tail;
                tail = tail->previous;

                if (tail == NULL) {
                    head = NULL;
                } else {
                    tail->next = NULL;
                }

                free(to_delete);
                break;
            }
            case QueryFront: {
                printf("%" PRIi32 "\n", head->value);
                break;
            }
        }
    }
    while (head != NULL) {
        List* to_delete = head;
        head = head->next;
        free(to_delete);
    }
    return 0;
}
