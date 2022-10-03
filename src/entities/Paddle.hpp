#ifndef _PADDLE_HPP_
#define _PADDLE_HPP_
#include "GameObject.hpp"

class Paddle : public GameObject{
private:
    KeyboardKey up;
    KeyboardKey down;
    char side;
public:
    Paddle(Vector2 pos, Vector2 vel, KeyboardKey up, KeyboardKey down, char side) :
        GameObject{pos, vel, {PADDLE_WIDTH, PADDLE_HEIGHT}}, up{up}, down{down}, side{side} {};
    ~Paddle() = default;

    void input() {
        if (IsKeyDown(down) && position.y <= SCREEN_HEIGHT - size.y)
        {
            velocity.y = PADDLE_SPEED;
        }
        else if (IsKeyDown(up) && position.y >= 0)
        {
            velocity.y = -PADDLE_SPEED;
        }
        else
            velocity.y = 0;
    }

    void update() override {
        position.y += velocity.y * GetFrameTime();
    }

    void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, RAYWHITE);
    }

    char getPaddleSide() {
        return side;
    }
};

#endif