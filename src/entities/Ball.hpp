#ifndef _BALL_HPP_
#define _BALL_HPP_
#include "GameObject.hpp"

#include "../audio/AudioManager.hpp"

class Ball : public GameObject
{
public:
    Ball(Vector2 pos, Vector2 vel) : GameObject{pos, vel, {BALL_SIZE, BALL_SIZE}} {};
    ~Ball() = default;

    void update() override {
        // Ball ceiling and floor bounce
        if (position.y < 0) {
            position.y = 0;
            AudioManager::Get().playSound(_WALL_BOUNCE);
            velocity.y = -velocity.y;
        }
        else if (position.y > SCREEN_HEIGHT - BALL_SIZE) {
            position.y = SCREEN_HEIGHT - BALL_SIZE;
            AudioManager::Get().playSound(_WALL_BOUNCE);
            velocity.y = -velocity.y;
        }

        position.x += velocity.x * GetFrameTime();
        position.y += velocity.y * GetFrameTime();
    }

    void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, BALL_COLOR);
    }
};

#endif