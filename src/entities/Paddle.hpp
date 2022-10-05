#ifndef _PADDLE_HPP_
#define _PADDLE_HPP_
#include "GameObject.hpp"
#include <math.h>

class Paddle : public GameObject{
private:
    KeyboardKey up;
    KeyboardKey down;
    char side;
    bool isCpu;
    Vector2 ballPos;
    float reactTimer;
public:
    Paddle(Vector2 pos, Vector2 vel, KeyboardKey up, KeyboardKey down, char side, bool isCpu) :
        GameObject{pos, vel, {PADDLE_WIDTH, PADDLE_HEIGHT}}, up{up}, down{down}, side{side}, isCpu{isCpu},
        ballPos{SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, reactTimer{0} {};
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
        if (isCpu) {
            if (reactTimer > CPU_PADDLE_REACT_TIME) {
                reactTimer = fmod(reactTimer, CPU_PADDLE_REACT_TIME);
                if (ballPos.x > SCREEN_WIDTH/2) {
                    if (ballPos.y > position.y + (size.y / 2) + (CPU_PADDLE_CENTER_RANGE/2)) velocity.y = PADDLE_SPEED;
                    else if (ballPos.y < position.y + (size.y / 2) - (CPU_PADDLE_CENTER_RANGE/2)) velocity.y = -PADDLE_SPEED;
                }
                else velocity.y = 0;
            } else reactTimer += GetFrameTime();
            if (position.y >= SCREEN_HEIGHT - size.y)
                position.y = SCREEN_HEIGHT - size.y;
            else if (position.y <= 0)
                position.y = 0;

            position.y += velocity.y * GetFrameTime();
        }
        else position.y += velocity.y * GetFrameTime();
    }

    void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, RAYWHITE);
    }

    char getPaddleSide() {
        return side;
    }

    bool getIsCpu() const {
        return isCpu;
    }

    void setBallPos(const Vector2 pos) {
        ballPos = pos;
    }
};

#endif