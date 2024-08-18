class Board {
   public:
    Piece* squares[8][8];

    void initialize();
    void printBoard();
    void movePiece(Move move);
    void getPieceAtPosition(Position pos);
};
