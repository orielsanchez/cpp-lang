#include "../include/Player.hpp"

Player::Player(const std::string &name, PieceColor pieceColor) {
  this->m_name = name;
  this->m_pieceColor = pieceColor;
}

std::string Player::getName() { return this->m_name; }

PieceColor Player::getPieceColor() { return this->m_pieceColor; }
