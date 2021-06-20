#pragma once
class board {
  // static means "it gets allocated for the lifetime of the program"
  // ie, even if I call this function 2 times, it won't get allocated
  // a second time
private:
  static const int ROWS = 3;
  static const int COLUMNS = 3;
  char arena[ROWS][COLUMNS];

  bool checkRowsAndColumns(const char &player);
  bool checkDiagonals(const char &player);

public:
  void initializeArena();
  void printArena() const;

  bool checkValidMove(const char &move);

  void updateArena(const char &move, const char &player);

  bool checkVictory(const char &player);
};
