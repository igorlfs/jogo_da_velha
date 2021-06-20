#include "board.hpp"

#include <iostream>
using std::cout;
using std::endl;

const int VALID = 0;
const int INVALID = 1;
const int WIN = 1;
const int NOTWIN = 0;

void board::initializeArena() {
  // Initialize numbers from 1 to 9
  char fillArena = '1';
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      this->arena[i][j] = fillArena;
      ++fillArena;
    }
  }
}
void board::printArena() const {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      cout << this->arena[i][j];
      // Doesn't print separator on last line
      if (j < ROWS - 1)
        cout << " │ ";
    }
    cout << endl;
    // Doesn't print separator on last column
    if (i < COLUMNS - 1) {
      cout << "──┼───┼──" << endl;
    }
  }
}
void board::updateArena(const char &move, const char &player) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      if (move == this->arena[i][j]) {
        this->arena[i][j] = player;
        printArena();
      }
    }
  }
}
bool board::checkValidMove(const char &move) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      if (move == this->arena[i][j])
        return VALID;
    }
  }
  return INVALID;
}
bool board::checkVictory(const char &player) {
  return (checkRowsAndColumns(player) || checkDiagonals(player));
}
bool board::checkRowsAndColumns(const char &player) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      if (this->arena[i][j] != player)
        break;
      if (j == COLUMNS - 1)
        return WIN;
    }
    for (int j = 0; j < COLUMNS; ++j) {
      if (this->arena[j][i] != player)
        break;
      if (j == COLUMNS - 1)
        return WIN;
    }
  }
  return NOTWIN;
}
bool board::checkDiagonals(const char &player) {
  for (int i = 0; i < ROWS; ++i) {
    if (this->arena[i][i] != player)
      break;
    if (i == ROWS - 1)
      return WIN;
  }
  for (int i = 0; i < ROWS; ++i) {
    if (this->arena[i][ROWS - (1 + i)] != player)
      break;
    if (i == ROWS - 1)
      return WIN;
  }
  return NOTWIN;
}
