#include <string>

#include "Board.hpp"
#include "Position.hpp"

class Piece {
    std::string color;
    Position position;

    void virtual generateLegalMoves(Board& board) = 0;
    void moveTo(Position newPosition);
};
