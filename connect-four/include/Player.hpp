#pragma once

#include "PieceColor.hpp"
#include <string>

class Player {
private:
  std::string m_name;
  PieceColor m_pieceColor;

public:
  Player(const std::string &name, PieceColor pieceColor);
  virtual ~Player() = 0;
  Player(std::string name, PieceColor pieceColor);
  virtual std::string getName() = 0;
  virtual PieceColor getPieceColor() = 0;
};
