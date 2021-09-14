#include "grid.hpp"

#include <iostream>

using std::cout;

static constexpr int VALID = 0;
static constexpr int INVALID = 1;
static constexpr int WIN = 1;
static constexpr int NOTWIN = 0;

char ticTacToe::getPlayers(const int &i) const { return this->players[i]; }
void ticTacToe::printArena() const {
    cout.put('\n');
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            this->printArenaHelper(i, j);
            if (j < ROWS - 1) cout << BLUE << " │ " << RESET;
        }
        (i < COLUMNS - 1) ? cout << BLUE << "\n──┼───┼──\n"
                                 << RESET
                          : cout << "\n\n";
    }
}
void ticTacToe::printArenaHelper(const int &i, const int &j) const {
    if (isdigit(this->arena[i][j]))
        cout << GREEN << this->arena[i][j] << RESET;
    else if (this->arena[i][j] == this->getPlayers(0))
        cout << RED << this->arena[i][j] << RESET;
    else
        cout << YELLOW << this->arena[i][j] << RESET;
}
void ticTacToe::updateArena(const char &move, const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (move == this->arena[i][j]) {
                this->arena[i][j] = player;
                return;
            }
        }
    }
}
bool ticTacToe::checkValidMove(const char &move) {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLUMNS; ++j)
            if (move == this->arena[i][j]) return VALID;
    return INVALID;
}
bool ticTacToe::checkVictory(const char &player) {
    return (checkRowsAndColumns(player) || checkDiagonals(player));
}
bool ticTacToe::checkRowsAndColumns(const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (this->arena[i][j] != player) break;
            if (j == COLUMNS - 1) return WIN;
        }
        for (int j = 0; j < COLUMNS; ++j) {
            if (this->arena[j][i] != player) break;
            if (j == COLUMNS - 1) return WIN;
        }
    }
    return NOTWIN;
}
bool ticTacToe::checkDiagonals(const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        if (this->arena[i][i] != player) break;
        if (i == ROWS - 1) return WIN;
    }
    for (int i = 0; i < ROWS; ++i) {
        if (this->arena[i][ROWS - (1 + i)] != player) break;
        if (i == ROWS - 1) return WIN;
    }
    return NOTWIN;
}
