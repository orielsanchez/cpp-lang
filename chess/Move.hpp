#include "Board.hpp"
#include "Piece.hpp"
#include "Position.hpp"
class Move {
   public:
    Position from;
    Position to;
    Piece* movedPiece;

    void execute(Board& board);
    void undo(Board& board);
};
