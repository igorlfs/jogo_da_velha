#include <iostream>
#include <regex>

#include "grid.hpp"

using namespace std;

char readInput();
void checkPlayer(ticTacToe &game, const int &i);
void checkTurn(char &player, const int &i);
void play(ticTacToe field);
bool isGameOver(ticTacToe field, const char player, const int countTurns);

int main() {
    ticTacToe game;

    checkPlayer(game, 0);
    checkPlayer(game, 1);
    game.initializeArena();
    play(game);
    return 0;
}

char readInput() {
    string line;

    getline(cin, line);
    if (cin.bad()) {
        cout << "Erro de leitura." << endl;
        exit(1);
    }
    return line[0];
}

void checkPlayer(ticTacToe &game, const int &i) {
    cout << "Jogador " << i + 1 << ", escolha uma letra: ";
readPlayerAgain:
    char playerChar = readInput();

    if (isalpha(playerChar)) {
        if (i == 0) {
            game.setPlayers(playerChar, i);
            return;
        } else if (game.getPlayers(0) != playerChar) {
            game.setPlayers(playerChar, i);
            return;
        }
        cout << "Jogador 2, você não pode escolher a mesma letra que o jogador "
                "1!"
             << endl
             << "Por favor, jogador 2, insira uma letra diferente: ";
        goto readPlayerAgain;
    } else {
        cout << "Erro na leitura" << endl;
        cout << "Por favor, jogador " << i << ", insira uma letra: ";
        goto readPlayerAgain;
    }
}

void checkTurn(char &turn, const int &i) {
    cout << "\nJogador " << i << ", escolha uma posição: ";
readTurnAgain:
    char turnChar = readInput();

    if (isdigit(turnChar) && (turnChar != '0')) {
        turn = turnChar;
    } else {
        cout << "Erro na leitura" << endl;
        cout << "Por favor, jogador " << i << ", insira um número não nulo: ";
        goto readTurnAgain;
    }
}

static constexpr int MAX_TURNS = 9;
static constexpr int MIN_TURNS_OVER = 3;
void play(ticTacToe game) {
    int countTurns = 0;

    while (countTurns < MAX_TURNS) {
        char currentPlayer =
            (countTurns % 2 == 0) ? game.getPlayers(0) : game.getPlayers(1);
        char move;
        do {
            checkTurn(move, countTurns % 2 + 1);
            if (game.checkValidMove(move)) {
                cout << "Jogada inválida!" << endl
                     << "Esse número não está disponível" << endl
                     << "Insira outro número" << endl;
            }
        } while (game.checkValidMove(move));
        game.updateArena(move, currentPlayer);
        if (countTurns > MIN_TURNS_OVER) {
            if (isGameOver(game, currentPlayer, countTurns)) {
                return;
            }
        }
        countTurns++;
    }
}

bool isGameOver(ticTacToe field, const char player, const int countTurns) {
    if (field.checkVictory(player)) {
        cout << "Parece que o jogador " << countTurns % 2 + 1 << " venceu!\n";
        return 1;
    }
    if (countTurns == MAX_TURNS - 1) {
        cout << "O jogo empatou!" << endl;
        return 1;
    }
    return 0;
}
