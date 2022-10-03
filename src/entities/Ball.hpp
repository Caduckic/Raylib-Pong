#ifndef _BALL_HPP_
#define _BALL_HPP_
#include "GameObject.hpp"

class Ball : public GameObject
{
public:
    Ball(Vector2 pos, Vector2 vel) : GameObject{pos, vel, {BALL_SIZE, BALL_SIZE}} {};
    ~Ball() = default;

    void update() override {
        position.x += velocity.x * GetFrameTime();
        position.y += velocity.y * GetFrameTime();

        // Ball ceiling and floor bounce
        if (position.y < 0 || position.y > 720 - 20)
        {
            velocity.y = -velocity.y;
        }
    }

    void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, BALL_COLOR);
    }
};

#endif