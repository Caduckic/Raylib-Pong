#ifndef _BALL_HPP_
#define _BALL_HPP_
#include "GameObject.hpp"

class Ball : public GameObject
{
public:
    Ball(Vector2 pos, Vector2 vel) : GameObject{pos, vel} {};
    ~Ball() = default;

    bool collided(Vector2 paddle) {
        return (position.x + BALL_SIZE > paddle.x &&
            position.x < paddle.x + PADDLE_WIDTH &&
            position.y > paddle.y - BALL_SIZE &&
            position.y < paddle.y + PADDLE_HEIGHT);
    }

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
        DrawRectangle(position.x, position.y, BALL_SIZE, BALL_SIZE, BALL_COLOR);
    }
};

#endif