#include "board.hpp"

#include <iostream>
using namespace std;
board::board() {
    char k = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            table[i][j] = k;
            k++;
        }
    }
}
void board::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << table[i][j];
            if (j < 3 - 1) cout << " │ ";
        }
        cout << endl;
        if (i < 3 - 1) {
            cout << "──┼───┼──\n";
        }
    }
}
bool board::checkValid(const char turn) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (turn == table[i][j]) return 1;
        }
    }
    return 0;
}
void board::updateBoard(const char turn, const char player) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (turn == table[i][j]) {
                table[i][j] = player;
                printBoard();
            }
        }
    }
}
bool board::checkVictory(const char player) {
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == player && table[i][1] == player &&
            table[i][2] == player)
            return 1;
        if (table[0][i] == player && table[1][i] == player &&
            table[2][i] == player)
            return 1;
    }
    if (table[0][0] == player && table[1][1] == player && table[2][2] == player)
        return 1;
    if (table[0][2] == player && table[1][1] == player && table[2][0] == player)
        return 1;
    return 0;
}
