#pragma once

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class ticTacToe {
  private:
    static const int ROWS = 3;
    static const int COLUMNS = 3;

    char arena[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    char players[2] = {'x', 'o'};

    bool checkRowsAndColumns(const char &player);
    bool checkDiagonals(const char &player);

    void printArenaHelper(const int &i, const int &j) const;

  public:
    char getPlayers(const int &i) const;
    void printArena() const;

    bool checkValidMove(const char &move);

    void updateArena(const char &move, const char &player);

    bool checkVictory(const char &player);
};
