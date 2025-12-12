#ifndef GAME_H
#define GAME_H

#include <pthread.h>

#define ROWS        6
#define COLS        7

#define PLAYER_NONE 0
#define PLAYER_ONE  1
#define PLAYER_TWO  2

struct game_state {
    unsigned char cells[ROWS * COLS];
    unsigned char current_player;
    unsigned char winner;
    int cursor_col;
    pthread_mutex_t mutex;
    int game_over;
};

// Find which row the token should drop to
// Returns the row index where the token should land, or -1 if column is full
int find_row(int col, const unsigned char *cells);

// Check if placing a token at (row, col) results in a win
int check_win(const unsigned char *cells, int row, int col, unsigned char player);

// Check if the board is completely full
int is_board_full(const unsigned char *cells);

#endif 

