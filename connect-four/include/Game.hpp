#pragma once

#include "Grid.hpp"
#include "Player.hpp"
#include <string>
#include <unordered_map>

class Game {
public:
  Game() = default;
  Game(Game &&) = default;
  Game(const Game &) = default;
  Game &operator=(Game &&) = default;
  Game &operator=(const Game &) = default;
  ~Game() = default;

  void printBoard();
  std::vector<int> playMove(Player *player);
  Player *playRound();
  void play();

private:
  Grid *grid;
  int connectN;
  std::unordered_map<std::string, int> score;
  int targetScore;
};
