#ifndef _MENUSTATE_HPP_
#define _MENUSTATE_HPP_

#include <vector>
#include <functional>
#include <memory>

#include "State.hpp"
#include "PlayState.hpp"

#include "../entities/MenuButton.hpp"
#include "../Exiter.hpp"

void CloseGame();

class MenuState : public State {
private:
    std::vector<MenuButton> buttons;
    //std::vector<MenuButton>::iterator it;
public:
    MenuState() : buttons
        {{{MENU_PLAY_POS_X, MENU_PLAY_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, "PLAY", MEDIUM_FONT_SIZE, std::make_shared<PlayState>()},
        {{MENU_QUIT_POS_X, MENU_QUIT_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, "QUIT", MEDIUM_FONT_SIZE, CloseGame}
        } {};
    ~MenuState() = default;

    virtual void update() override {
        for (auto& button : buttons) {
            button.update();
        }
    }

    virtual void render() override {
        DrawText(TITLE_NAME, TITLE_POS_X, TITLE_POS_Y, LARGE_FONT_SIZE, RAYWHITE);
        for (auto& button : buttons) {
            button.draw();
        }
    }
};

void CloseGame() {
    Exiter::Get().CloseGame();
}

#endif