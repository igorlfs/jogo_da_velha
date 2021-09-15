#include "grid.hpp"

#include <iostream>

using std::cout;
using namespace TicTacToe;

void game::printArena() const {
    cout.put('\n');
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            this->printArenaHelper(i, j);
            if (j < ROWS - 1) cout << BLUE << " │ " << RESET;
        }
        (i < COLS - 1) ? cout << BLUE << "\n──┼───┼──\n"
                              << RESET
                       : cout << "\n\n";
    }
}
void game::printArenaHelper(const int &i, const int &j) const {
    if (isdigit(this->arena[i][j]))
        cout << GREEN << this->arena[i][j] << RESET;
    else if (this->arena[i][j] == this->getPlayer(0))
        cout << RED << this->arena[i][j] << RESET;
    else
        cout << YELLOW << this->arena[i][j] << RESET;
}
void game::updateArena(const char &move, const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (move == this->arena[i][j]) {
                this->arena[i][j] = player;
                return;
            }
        }
    }
}
bool game::isInvalidMove(const char &move) {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            if (move == this->arena[i][j]) return 0;
    return 1;
}
bool game::checkRowsAndColumns(const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (this->arena[i][j] != player) break;
            if (j == COLS - 1) return 1;
        }
        for (int j = 0; j < COLS; ++j) {
            if (this->arena[j][i] != player) break;
            if (j == COLS - 1) return 1;
        }
    }
    return 0;
}
bool game::checkDiagonals(const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        if (this->arena[i][i] != player) break;
        if (i == ROWS - 1) return 1;
    }
    for (int i = 0; i < ROWS; ++i) {
        if (this->arena[i][(ROWS - 1) - (i)] != player) break;
        if (i == ROWS - 1) return 1;
    }
    return 0;
}
