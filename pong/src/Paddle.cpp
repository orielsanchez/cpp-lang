#ifndef PADDLE
#define PADDLE

#include "Vec2.cpp"
#include <SDL_rect.h>
#include <SDL_render.h>

const int PADDLE_WIDTH = 15;
const int PADDLE_HEIGHT = 45;

class Paddle {

  public:
    Paddle(Vec2 position) : position(position) {
        rect.x = static_cast<int>(position.x);
        rect.y = static_cast<int>(position.y);
        rect.w = PADDLE_WIDTH;
        rect.h = PADDLE_HEIGHT;
    }

    void Draw(SDL_Renderer *renderer) {
        rect.y = static_cast<int>(position.y);
        SDL_RenderFillRect(renderer, &rect);
    }

    Vec2 position;
    SDL_Rect rect{};

  private:
};

#endif // PADDLE
