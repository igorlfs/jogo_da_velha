#include <iostream>

#include "board.hpp"
using namespace std;
void readInput(char &input) {
    cin >> input;
    if (cin.good() == false) {
        cout << "Error reading input.\n";
        exit(1);
    }
}
int main() {
    char playerOne = '\0';
    char playerTwo = '\0';
    cout << "Choose your character (X or O): ";
    readInput(playerOne);
    for (; playerOne != 'X' && playerOne != 'O';) {
        cout << "Dude, just choose between 'X' and 'O': ";
        readInput(playerOne);
    }

    if (playerOne == 'X')
        playerTwo = 'O';
    else
        playerTwo = 'X';

    board field;
    field.printBoard();
    int countTurns = 0;
    while (countTurns < 9) {
        char turn = '\0';
        char currentPlayer = '\0';
        if (countTurns % 2 == 0)
            currentPlayer = playerOne;
        else
            currentPlayer = playerTwo;
        cout << "\nPlayer " << countTurns % 2 + 1 << "'s turn: ";
    tryagain:
        do {
            readInput(turn);
        } while (turn != '1' && turn != '2' && turn != '3' && turn != '4' &&
                 turn != '5' && turn != '6' && turn != '7' && turn != '8' &&
                 turn != '9');
        if (!field.checkValid(turn)) {
            cout << "Invalid move!\nThis number is no longer on the table!\n"
                    "Insert another number: ";
            goto tryagain;
        }
        field.updateBoard(turn, currentPlayer);
        if (countTurns > 3) {
            if (field.checkVictory(currentPlayer)) {
                cout << "It looks like player " << countTurns % 2 + 1
                     << " won!\n";
                return 0;
            }
        }
        countTurns++;
    }
    cout << "It looks like a draw!\n";
    return 0;
}
