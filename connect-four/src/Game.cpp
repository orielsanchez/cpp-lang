#pragma once

#include "Grid.cpp"
#include "Player.cpp"
#include <cstddef>
#include <print>
#include <string>
#include <unordered_map>
#include <vector>

class Game {
private:
  Grid *grid;
  int connectN;
  std::vector<Player *> players;
  std::unordered_map<std::string, int> score;
  int targetScore;

public:
  Game(Grid *grid, int connectN, int targetScore) {
    this->grid = grid;
    this->connectN = connectN;
    this->targetScore = targetScore;

    this->players =
        std::vector<Player *>{new Player("Player 1", PieceColor::RED),
                              new Player("Player 2", PieceColor::YELLOW)};

    for (const auto &player : this->players) {
      this->score.insert({player->getName(), 0});
    }
  }

  void printBoard() {
    std::println("Board:");
    std::vector<std::vector<PieceColor>> print_grid = this->grid->getGrid();
    for (size_t i = 0; i < print_grid.size(); i++) {
      std::string row = "";
      for (auto piece : print_grid[i]) {
        if (piece == PieceColor::EMPTY) {
          row.append("0 ");
        } else if (piece == PieceColor::RED) {
          row.append("R ");
        } else if (piece == PieceColor::YELLOW) {
          row.append("Y ");
        }
      }
      std::println("${}", row);
    }
    std::println("");
  };

  std::vector<int> playMove(Player *player){

  };
  Player *playRound(){

  };

  void play(){
      //

  };
};