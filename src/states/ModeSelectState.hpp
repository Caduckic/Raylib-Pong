#ifndef _MODESELECTSTATE_HPP_
#define _MODESELECTSTATE_HPP_

#include <vector>
#include <functional>

#include "State.hpp"

#include "../entities/MenuButton.hpp"
#include "PlayState.hpp"

void PopSelect();

class ModeSelectState : public State {
private:
    std::vector<MenuButton> buttons;
public:
    ModeSelectState() : buttons
        {{{(SCREEN_WIDTH / 2) - MENU_BUTTON_SIZE_X - 100, MENU_PLAY_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, "PvCPU", MEDIUM_FONT_SIZE, std::make_shared<PlayState>(true)},
        {{(SCREEN_WIDTH / 2) + 100, MENU_PLAY_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, "PvP", MEDIUM_FONT_SIZE, std::make_shared<PlayState>(false)},
        {{SMALL_BUTTON_POS_X, SMALL_BUTTON_POS_Y}, {SMALL_BUTTON_SIZE_X, SMALL_BUTTON_SIZE_Y}, "BACK", SMALL_FONT_SIZE, PopSelect}} {};
    ~ModeSelectState() = default;

    virtual void update() override {
        for (auto& button : buttons) {
            button.update();
        }
    }

    virtual void render() override {
        for (auto& button : buttons) {
            button.draw();
        }
    }
};

void PopSelect() {
    StateManager::Get().popState();
}

#endif