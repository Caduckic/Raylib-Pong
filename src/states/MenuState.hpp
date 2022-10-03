#ifndef _MENUSTATE_HPP_
#define _MENUSTATE_HPP_

#include <vector>
#include <functional>

#include "State.hpp"

#include "../entities/MenuButton.hpp"

void CloseGame();

class MenuState : public State {
private:
    std::vector<MenuButton> buttons;
    std::vector<MenuButton>::iterator it;
    std::function<void()> push;
    Vector2 mousePos;
public:
    MenuState(std::function<void()> push) : push{push},
        buttons{{{MENU_PLAY_POS_X, MENU_PLAY_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, "PLAY", MEDIUM_FONT_SIZE, push},
            {{MENU_QUIT_POS_X, MENU_QUIT_POS_Y}, {MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y}, "QUIT", MEDIUM_FONT_SIZE, CloseGame}
        } {};
    ~MenuState() = default;

    virtual void update() override {
        for (auto& button : buttons) {
            button.update();
        }
        if (IsKeyPressed(KEY_F)) {
            push();
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
    CloseWindow();
}

#endif