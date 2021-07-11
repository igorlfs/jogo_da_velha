#include <iostream>
#include <regex>

#include "board.hpp"

using namespace std;

char readInput();
void checkPlayer(char &player, const int &i);
void checkTurn(char &player, const int &i);
void play(board field, const char p1, const char p2);
bool isGameOver(board field, const char player, const int countTurns);
int main() {

  char players[2];
  checkPlayer(players[0], 1);
  do {
    checkPlayer(players[1], 2);
    if (players[0] == players[1]) {
      cout << "Jogador 2, você não pode escolher a mesma letra que o jogador 1!"
           << endl;
    }
  } while (players[0] == players[1]);

  ticTacToe field;
  field.initializeArena();
  field.printArena();
  play(field, players[0], players[1]);

  return 0;
}
char readInput() {
  string line;
  getline(cin, line);
  if (cin.good() == false) {
    cout << "Erro de leitura." << endl;
    exit(1);
  }
  return line[0];
}
void checkPlayer(char &player, const int &i) {
  cout << "Jogador " << i << ", escolha uma letra: ";
readPlayerAgain:
  char playerChar = readInput();
  if (isalpha(playerChar)) {
    player = playerChar;
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
  if (isdigit(turnChar) && turnChar != '0') {
    turn = turnChar;
  } else {
    cout << "Erro na leitura" << endl;
    cout << "Por favor, jogador " << i << ", insira um número não nulo: ";
    goto readTurnAgain;
  }
}
static constexpr int MAX_TURNS = 9;
static constexpr int MIN_TURNS_OVER = 3;
void play(board field, const char p1, const char p2) {
  int countTurns = 0;
  while (countTurns < MAX_TURNS) {
    char currentPlayer = (countTurns % 2 == 0) ? p1 : p2;
    char move;
    do {
      checkTurn(move, countTurns % 2 + 1);
      if (field.checkValidMove(move)) {
        cout << "Jogada inválida!" << endl
             << "Esse número não está disponível" << endl
             << "Insira outro número" << endl;
      }
    } while (field.checkValidMove(move));
    field.updateArena(move, currentPlayer);
    if (countTurns > MIN_TURNS_OVER) {
      if (isGameOver(field, currentPlayer, countTurns)) {
        return;
      }
    }
    countTurns++;
  }
}
bool isGameOver(board field, const char player, const int countTurns) {
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
