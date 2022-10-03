#ifndef _PLAYSTATE_HPP_
#define _PLAYSTATE_HPP_
#include <cmath>
#include <string>
#include <functional>
#include "../config.hpp"
#include "State.hpp"

#include "../entities/Paddle.hpp"
#include "../entities/Ball.hpp"
#include "../entities/MenuButton.hpp"

#include "../audio/AudioManager.hpp"

float GetRandBallYVel();
float GetRandVelOffset();
void HitBall(Ball& ball, Paddle& paddle, float startX);

class PlayState : public State {
private:
    MenuButton exit;
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;
    float countDownTimer;
    int player1Score;
    int player2Score;
    std::function<void()> pop;
public:
    PlayState(std::function<void()> pop) : pop{pop}, paddle1{{PADDLE_WALL_DIST, PADDLE_START_Y}, {0,0}, KEY_W, KEY_S, 'L'},
        paddle2{{SCREEN_WIDTH - PADDLE_WALL_DIST - PADDLE_WIDTH, PADDLE_START_Y}, {0,0}, KEY_UP, KEY_DOWN, 'R'},
        ball{{BALL_START_X, BALL_START_Y}, {((float)rand() / RAND_MAX > 0.5) ? BALL_SPEED : -BALL_SPEED, GetRandBallYVel()}},
        countDownTimer{COUNT_DOWN_TIME}, player1Score{0}, player2Score{},
        exit{{SMALL_BUTTON_POS_X, SMALL_BUTTON_POS_Y}, {SMALL_BUTTON_SIZE_X, SMALL_BUTTON_SIZE_Y}, "EXIT", SMALL_FONT_SIZE, pop} {};
    ~PlayState() = default;

    virtual void update() override {
        exit.update();
        if (countDownTimer > 0)
        {
            countDownTimer -= GetFrameTime();
        }

        // Player inputs
        paddle1.input();
        paddle2.input();

        // Player updates
        paddle1.update();
        paddle2.update();
        

        if (countDownTimer <= 0)
        {
            ball.update();
            if (ball.collided(paddle1)) {
                AudioManager::Get().playSound(_PADDLE_BOUNCE);
                HitBall(ball, paddle1, paddle1.getPosition().x + paddle1.getSize().x);
            }
            if (ball.collided(paddle2)) {
                AudioManager::Get().playSound(_PADDLE_BOUNCE);
                HitBall(ball, paddle2, paddle2.getPosition().x - ball.getSize().x);
            }

            // Player 1 scores
            if (ball.getPosition().x > SCREEN_WIDTH) {
                player1Score++;
                AudioManager::Get().playSound(_SCORE);
                ball.setPosition({BALL_START_X, BALL_START_Y});
                ball.setVelocity({-BALL_SPEED, GetRandBallYVel()});
                countDownTimer = COUNT_DOWN_TIME;
            }

            // Player 2 scores
            if (ball.getPosition().x < -ball.getSize().x) {
                player2Score++;
                AudioManager::Get().playSound(_SCORE);
                ball.setPosition({BALL_START_X, BALL_START_Y});
                ball.setVelocity({BALL_SPEED, GetRandBallYVel()});
                countDownTimer = COUNT_DOWN_TIME;
            }
        }
    }

    virtual void render() override {
        // Draw Scores
        DrawText(std::to_string(player1Score).c_str(),
                 (SCREEN_WIDTH / 2) - SCORE_TEXT_BETWEEN_OFFSET - (MeasureText(std::to_string(player1Score).c_str(), SMALL_FONT_SIZE) / 2),
                 SCORE_TEXT_TOP_OFFSET, SMALL_FONT_SIZE, RAYWHITE);
        DrawText(std::to_string(player2Score).c_str(),
                 (SCREEN_WIDTH / 2) + SCORE_TEXT_BETWEEN_OFFSET - (MeasureText(std::to_string(player2Score).c_str(), SMALL_FONT_SIZE) / 2),
                 SCORE_TEXT_TOP_OFFSET, SMALL_FONT_SIZE, RAYWHITE);

        // Draw ball
        ball.draw();
        //DrawRectangle(ballX, ballY, BALL_SIZE, BALL_SIZE, BALL_COLOR);

        // Draw paddles
        paddle1.draw();
        paddle2.draw();

        if (countDownTimer > 0)
        {
            DrawText(std::to_string((int)countDownTimer + 1).c_str(),
                     (SCREEN_WIDTH / 2) - (MeasureText(std::to_string((int)countDownTimer + 1).c_str(), LARGE_FONT_SIZE) / 2),
                     (SCREEN_HEIGHT / 2) - (LARGE_FONT_SIZE / 2), LARGE_FONT_SIZE, RAYWHITE);
        }

        // Draw Exit button
        exit.draw();
    }
};

float GetRandVelOffset() {
    return (float)rand() / RAND_MAX * BALL_VELOCITY_OFFSET;
}

float GetRandBallYVel() {
    if ((float)rand() / RAND_MAX > 0.5)
    {
        return BALL_SPEED + GetRandVelOffset();
    }
    else
        return -(BALL_SPEED + GetRandVelOffset());
}

void HitBall(Ball& ball, Paddle& paddle, float startX) {
    ball.setPosition({startX, ball.getPosition().y});
    float increase = (paddle.getPaddleSide() == 'L') ? BALL_SPEED_INCREASE : -BALL_SPEED_INCREASE;
    Vector2 velocity {-(ball.getVelocity().x - increase), ball.getVelocity().y};
    if (ball.getPosition().y < paddle.getPosition().y + (paddle.getSize().y / 2) && paddle.getVelocity().y < 0)
        velocity.y = -50 + -(8 * (paddle.getPosition().y + (paddle.getSize().y / 2) - ball.getPosition().y));
    else if (ball.getPosition().y > paddle.getPosition().y + (paddle.getSize().y / 2) && paddle.getVelocity().y > 0) {
        velocity.y = 50 +(8 * std::abs(paddle.getPosition().y + (paddle.getSize().y / 2) - ball.getPosition().y));
    }
    ball.setVelocity(velocity);
}

#endif