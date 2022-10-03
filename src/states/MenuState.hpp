#ifndef _MENUSTATE_HPP_
#define _MENUSTATE_HPP_

#include <vector>
#include <functional>

#include "State.hpp"

#include "../entities/MenuButton.hpp"
//#include "StateManager.hpp"

class MenuState : public State {
private:
    std::vector<MenuButton> buttons;
    std::vector<MenuButton>::iterator it;
    std::function<void()> push;
    Vector2 mousePos;
public:
    MenuState(std::function<void()> push) : push{push}, buttons{{{SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 75}, "Test button"}} {};
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
        for (auto& button : buttons) {
            button.draw();
        }
    }
};

#endif