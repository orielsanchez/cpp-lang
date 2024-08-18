
#include "Board.hpp"
#include "Player.hpp"
class Game {
   public:
    Player whitePlayer;
    Player blackPlayer;
    Board board;
    bool isGameOver;

    void start();
    void end();
    void switchTurns();
    void checkGameState();
};
