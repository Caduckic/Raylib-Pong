#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include "UIElement.hpp"
#include "../states/StateManager.hpp"
#include "../states/State.hpp"
#include "../audio/AudioManager.hpp"

#include <functional>
#include <string>
#include <map>
#include <memory>

class MenuButton : public UIElement {
private:
    std::function<void()> click;
    std::shared_ptr<State> nextState;
public:
    MenuButton(Vector2 pos, Vector2 size, std::string text, int fontSize, std::function<void()> press) : 
        UIElement(pos, size, text, fontSize), click{press} {
        initMenuColors();
    };
    MenuButton(Vector2 pos, Vector2 size, std::string text, int fontSize, std::shared_ptr<State> nextState) :
        UIElement(pos, size, text, fontSize), click{NULL}, nextState{nextState} {
        initMenuColors();
    };
    ~MenuButton() = default;

    void update() override {
        if (CompareColors(color, menuColors[PRESSED]) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            AudioManager::Get().playSound(_BUTTON);
            if (click != NULL) click();
            else {
                nextState->init();
                StateManager::Get().pushState(nextState);
            }
        }

        // project built without c++ wrapper, won't be adding operator overloading to Color
        if (cursorCollided()) {
            if (CompareColors(color, menuColors[DEFAULT]))
                color = menuColors[SELECTED];
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                color = menuColors[PRESSED];
        }
        else {
            color = menuColors[DEFAULT];
        }
    }

    virtual void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, color);

        DrawText(text.c_str(), position.x + (size.x / 2) - MeasureText(text.c_str(), fontSize) / 2 + (fontSize / FONT_SHADOW_OFFSET),
            position.y + (size.y / 2) - (fontSize / 2) + (fontSize / FONT_SHADOW_OFFSET), fontSize, {0,0,0,60});
        DrawText(text.c_str(), position.x + (size.x / 2) - MeasureText(text.c_str(), fontSize) / 2,
            position.y + (size.y / 2) - (fontSize / 2), fontSize, RAYWHITE);
    }
};
#endif