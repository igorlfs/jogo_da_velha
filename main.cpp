#include <iostream>

#include "board.hpp"
using std::cin;
using std::cout;
using std::endl;
void readInput(char &input) {
    cin >> input;
    if (cin.good() == false) {
        cout << "Error reading input.\n";
        exit(1);
    }
}
int main() {
    char player1;
    char player2;
    cout << "Choose your character (X or O): ";
    readInput(player1);
    while (player1 != 'X' && player1 != 'O') {
        cout << "Dude, just choose between 'X' and 'O': ";
        readInput(player1);
    }
    if (player1 == 'X') {
        player2 = 'O';
    } else {
        player2 = 'X';
    }
    board field;
    field.initializeArena();
    field.printArena();
    int countTurns = 0;
    while (countTurns < 9) {
        char turn;
        char currentPlayer;
        if (countTurns % 2 == 0)
            currentPlayer = player1;
        else
            currentPlayer = player2;
        cout << "\nPlayer " << countTurns % 2 + 1 << "'s turn: ";
    tryagain:
        do {
            readInput(turn);
        } while (turn != '1' && turn != '2' && turn != '3' && turn != '4' &&
                 turn != '5' && turn != '6' && turn != '7' && turn != '8' &&
                 turn != '9');
        if (!field.checkValidMove(!turn)) {
            cout << "Invalid move!\nThis number is no longer on the table!\n"
                    "Insert another number: ";
            goto tryagain;
        }
        field.updateArena(turn, currentPlayer);
        if (countTurns > 3) {
            if (field.checkVictory(currentPlayer)) {
                cout << "It looks like player " << countTurns % 2 + 1
                     << " won!\n";
                return 0;
            }
        }
        countTurns++;
    }
    cout << "It looks like a draw!" << endl;
    return 0;
}
