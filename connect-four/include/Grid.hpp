#pragma once

#include <vector>

class Grid {

private:
  int rows;
  int columns;
  std::vector<std::vector<int>> grid;

public:
  Grid(int rows, int columns);
  Grid(const Grid &other);
  Grid(Grid &&other) noexcept;
  virtual ~Grid(){};
  virtual Grid &operator=(const Grid &other);
  virtual Grid &operator=(Grid &&other) noexcept;

  virtual void initGrid();
  virtual std::vector<std::vector<int>> getGrid();
  virtual int getColumnCount();
  virtual int placePiece();
  virtual bool checkNConnected();
};
