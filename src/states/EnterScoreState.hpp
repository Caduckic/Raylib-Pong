#ifndef _ENTERSCORESTATE_HPP_
#define _ENTERSCORESTATE_HPP_

#include "../SaveManager.hpp"

#include "StateManager.hpp"
#include "State.hpp"
#include "../entities/InputField.hpp"
#include "../entities/MenuButton.hpp"
#include <string>
#include <functional>


class EnterScoreState : public State {
private:
    int score;
    InputField nameInput;
    MenuButton submitButton;
public:
    EnterScoreState(int score) : score{score},
        nameInput{{MENU_PLAY_POS_X, MENU_PLAY_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, MEDIUM_FONT_SIZE},
        submitButton{{SMALL_BUTTON_POS_X, SMALL_BUTTON_POS_Y}, {SMALL_BUTTON_SIZE_X, SMALL_BUTTON_SIZE_Y}, "Submit", SMALL_FONT_SIZE,
            [this](){SaveManager::Get().saveScore(this->nameInput.getText(), this->score); StateManager::Get().popStates(3);}} {};
    ~EnterScoreState() = default;

    virtual void init() {};
    virtual void update() override {
        nameInput.update();
        submitButton.update();
    }
    virtual void render() override {
        DrawText((SCORE_STRING + std::to_string(score)).c_str(),
            SCREEN_WIDTH/2 - MeasureText((SCORE_STRING + std::to_string(score)).c_str(), MEDIUM_FONT_SIZE)/2,
            TITLE_POS_Y, MEDIUM_FONT_SIZE, RAYWHITE);
        nameInput.draw();
        submitButton.draw();
    }
};

#endif