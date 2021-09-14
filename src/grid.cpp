#include "grid.hpp"

#include <iostream>
using std::cout;
using std::endl;

static constexpr int VALID = 0;
static constexpr int INVALID = 1;
static constexpr int WIN = 1;
static constexpr int NOTWIN = 0;

char ticTacToe::getPlayers(const int &i) const { return this->players[i]; }
void ticTacToe::setPlayers(const char &player, const int &i) {
    this->players[i] = player;
}
void ticTacToe::initializeArena() {
    // Initialize numbers from 1 to 9
    char fillArena = '1';
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            this->arena[i][j] = fillArena;
            ++fillArena;
        }
    }
    this->printArena();
}
void ticTacToe::printArena() const {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            this->printArenaHelper(i, j);
            // Doesn't print separator on last line
            if (j < ROWS - 1) cout << BLUE << " │ " << RESET;
        }
        cout << endl;
        // Doesn't print separator on last column
        if (i < COLUMNS - 1) {
            cout << BLUE << "──┼───┼──" << RESET << endl;
        }
    }
}
void ticTacToe::printArenaHelper(const int &i, const int &j) const {
    if (isdigit(this->arena[i][j])) {
        cout << GREEN << this->arena[i][j] << RESET;
    } else if (this->arena[i][j] == this->getPlayers(0)) {
        cout << RED << this->arena[i][j] << RESET;
    } else {
        cout << YELLOW << this->arena[i][j] << RESET;
    }
}
void ticTacToe::updateArena(const char &move, const char &player) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (move == this->arena[i][j]) {
                this->arena[i][j] = player;
                printArena();
                return;
            }
        }
    }
}
bool ticTacToe::checkValidMove(const char &move) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (move == this->arena[i][j]) return VALID;
        }
    }
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
