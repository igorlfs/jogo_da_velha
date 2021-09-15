#pragma once

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

namespace TicTacToe {

static const int ROWS = 3;
static const int COLS = 3;
static const int MAX = ROWS * COLS;

class game {
  private:
    char arena[ROWS][COLS]{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    constexpr static char players[2]{'x', 'o'};

    void printArenaHelper(const int &i, const int &j) const;

    bool checkRowsAndColumns(const char &player);
    bool checkDiagonals(const char &player);

  public:
    void printArena() const;

    char getPlayer(const int &i) const { return this->players[i]; };
    bool isInvalidMove(const char &move);
    void updateArena(const char &move, const char &player);

    bool checkVictory(const char &player) {
        return (checkRowsAndColumns(player) || checkDiagonals(player));
    }
};
} // namespace TicTacToe
