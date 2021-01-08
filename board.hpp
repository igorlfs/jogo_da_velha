#ifndef BOARD
#define BOARD
struct board {
    char table[3][3];
    board();
    void printBoard();
    bool checkValid(const char turn);
    void updateBoard(const char turn, const char player);
    bool checkVictory(const char player);
};
#endif
