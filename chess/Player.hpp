#include <string>

#include "Board.hpp"

class Player {
   public:
    std::string name;
    bool isWhite;
    bool isHuman;

    void makeMove(Board& board);
    void getAvailableMoves(Board& board);
};
