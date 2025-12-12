// 礼物
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define EDGE 3
#define BOARD_LEN (10 + EDGE + EDGE)
#define PIECE_LEN (EDGE + 1)
int32_t get_index(int32_t i, int32_t j, int32_t size) {
    return i * size + j;
}
bool have_enough_space(
    const int32_t* board,
    const int32_t* piece,
    int32_t start_i,
    int32_t start_j
) {
    for (int32_t i = 0; i < PIECE_LEN; i++) {
        for (int32_t j = 0; j < PIECE_LEN; j++) {
            int32_t board_i = i + start_i;
            int32_t board_j = j + start_j;

            int32_t board_index = get_index(board_i, board_j, BOARD_LEN);
            int32_t piece_index = get_index(i, j, PIECE_LEN);
            if (piece[piece_index] == 1) {
                bool have_enough_space = true;
                have_enough_space = have_enough_space && board[board_index] == 0;
                have_enough_space =
                    have_enough_space && (board_i >= EDGE && board_i < BOARD_LEN - EDGE);
                have_enough_space =
                    have_enough_space && (board_j >= EDGE && board_j < BOARD_LEN - EDGE);
                if (!have_enough_space) {
                    return false;
                }
            }
        }
    }
    return true;
}
int32_t main(void) {
    int32_t* board = calloc(BOARD_LEN * BOARD_LEN, sizeof(int32_t));

    for (int32_t i = EDGE; i < BOARD_LEN - EDGE; i++) {
        for (int32_t j = EDGE; j < BOARD_LEN - EDGE; j++) {
            int32_t index = get_index(i, j, BOARD_LEN);
            scanf("%" PRIi32, &board[index]);
        }
    }

    int32_t* piece = calloc(PIECE_LEN * PIECE_LEN, sizeof(int32_t));
    for (int32_t i = 0; i < PIECE_LEN; i++) {
        for (int32_t j = 0; j < PIECE_LEN; j++) {
            int32_t index = get_index(i, j, PIECE_LEN);
            scanf("%" PRIi32, &piece[index]);
        }
    }

    int32_t space_count = 0;
    for (int32_t i = 0; i < BOARD_LEN - EDGE; i++) {
        for (int32_t j = 0; j < BOARD_LEN - EDGE; j++) {
            if (have_enough_space(board, piece, i, j)) {
                space_count++;
            }
        }
    }

    printf("%" PRIi32 "\n", space_count);
    free(piece);
    free(board);
    return 0;
}
