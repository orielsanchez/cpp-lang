#pragma once

#include "PieceColor.cpp"
#include <string>

class Player {
private:
  std::string m_name;
  PieceColor m_pieceColor;

public:
  Player(const std::string &name, PieceColor pieceColor) {
    this->m_name = name;
    this->m_pieceColor = pieceColor;
  }

  std::string getName() { return this->m_name; }
  PieceColor getPieceColor() { return this->m_pieceColor; }
};
