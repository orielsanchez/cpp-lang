#pragma once

#include "PieceColor.cpp"
#include <vector>

class Grid {

private:
  int rows;
  int columns;
  std::vector<std::vector<PieceColor>> grid;

public:
  Grid(int rows, int columns);

  void initGrid() {
    for (auto i = 0; i < (int)grid.size(); i++) {
      for (auto j = 0; j < (int)grid[i].size(); j++) {
        grid[i][j] = PieceColor::EMPTY;
      }
    }
  }
  std::vector<std::vector<PieceColor>> getGrid();
  int getColumnCount();
  int placePiece();
  bool checkNConnected();
};