#include "game.h"

/** Check if a player has won by counting tokens in a direction
 * @param cells The game board cells
 * @param row The row index to start counting from
 * @param col The column index to start counting from
 * @param row_step The row direction step (1, -1, or 0)
 * @param col_step The column direction step (1, -1, or 0)
 * @param player The player to count tokens for
 * 
 * @return The total count of consecutive tokens in both directions
 */
static int count_in_direction(const unsigned char *cells, int row, int col,
                               int row_step, int col_step, unsigned char player) {
    int count = 0;
    int r = row;
    int c = col;
    while (r >= 0 && r < ROWS && c >= 0 && c < COLS && cells[r * COLS + c] == player) {
        count++; r += row_step; c += col_step;
    }
    // Count the opposite direction
    r = row - row_step; 
    c = col - col_step;
    while (r >= 0 && r < ROWS && c >= 0 && c < COLS && cells[r * COLS + c] == player) {
        count++; r -= row_step; c -= col_step;
    }
    return count;
}

/**  Find which row the token should drop to
 * @param col The column index where the token is being dropped
 * @param cells The game board cells
 * 
 * @return The row index where the token should land, or -1 if column is full
 * */
int find_row(int col, const unsigned char *cells) {
    // Check for the available row in the column 
    for (int row = ROWS - 1; row >= 0; row--) {
        if (cells[row * COLS + col] == PLAYER_NONE) return row;
    }
    return -1; 
}

/** Check if placing a token at (row, col) results in a win
 * @param cells The game board cells
 * @param row The row index where the token was placed
 * @param col The column index where the token was placed
 * @param player The player who placed the token
 * 
 * @return 1 if the player wins, 0 otherwise
 */
int check_win(const unsigned char *cells, int row, int col, unsigned char player) {
    if (player == PLAYER_NONE) return 0;
    if (count_in_direction(cells, row, col, 0, 1, player) >= 4) return 1;
    if (count_in_direction(cells, row, col, 1, 0, player) >= 4) return 1;
    if (count_in_direction(cells, row, col, 1, 1, player) >= 4) return 1;
    if (count_in_direction(cells, row, col, 1, -1, player) >= 4) return 1;
    return 0;
}

/** Check if the board is completely full
 * @param cells The game board cells
 * 
 * @return 1 if the board is full, 0 otherwise
 */
int is_board_full(const unsigned char *cells) {
    for (int col = 0; col < COLS; col++) {
        if (cells[col] == PLAYER_NONE) return 0;
    }
    return 1;
}

