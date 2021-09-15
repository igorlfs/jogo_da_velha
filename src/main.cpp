#include <iostream>
#include <regex>

#include "grid.hpp"

using namespace std;

struct interrupt {};
struct wrongFormat {};

void play(TicTacToe::game field);
void readMove(char &move, const char &i);

int main() {
    TicTacToe::game game;
    game.printArena();
    play(game);
    return 0;
}

void play(TicTacToe::game game) {
    for (int turns = 0; turns < TicTacToe::MAX; turns++) {
        char currentPlayer =
            (turns % 2 == 0) ? game.getPlayer(0) : game.getPlayer(1);
        char move;
        do {
            readMove(move, game.getPlayer(turns % 2));
            if (game.isInvalidMove(move)) {
                cout << "Jogada inválida!" << endl
                     << "Esse número não está disponível" << endl
                     << "Insira outro número" << endl;
            }
        } while (game.isInvalidMove(move));
        game.updateArena(move, currentPlayer);
        game.printArena();
        if (game.checkVictory(move)) {
            cout << "O jogador " << turns % 2 + 1 << " venceu!\n";
            return;
        }
    }
    cout << "O jogo empatou!\n";
}

void readMove(char &move, const char &i) {
readMoveAgain:
    cout << "\n[" << i << "] escolha uma posição: ";
    try {
        std::regex expected("[1-9]");
        std::string readLine;
        std::getline(std::cin, readLine);

        if (std::cin.eof()) throw interrupt();
        if (!std::regex_match(readLine, expected)) throw wrongFormat();

        std::stringstream ss(readLine);
        char moveChar;
        ss >> moveChar;
        move = moveChar;

    } catch (interrupt e) {
        std::cout << "\n\nA entrada de dados foi interrompida. Saindo.\n\n";
        exit(EXIT_FAILURE);
    } catch (wrongFormat e) {
        cout << "Erro na leitura\n"
                "Por favor, ["
             << i << "], insira um número entre 1 e 9\n";
        goto readMoveAgain;
    }
}
