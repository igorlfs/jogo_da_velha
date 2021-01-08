#ifndef BOARD_R
#define BOARD_R 3
#endif
#ifndef BOARD_C
#define BOARD_C 3
#endif
#ifndef BOARD
#define BOARD
struct board {
    char table[BOARD_R][BOARD_C];
    board();
    void printBoard();
    bool checkValid(const char turn);
    void updateBoard(const char turn, const char player);
    bool checkVictory(const char player);
};
#endif
