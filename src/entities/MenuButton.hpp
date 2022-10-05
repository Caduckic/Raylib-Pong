#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include "GameObject.hpp"
#include "../states/StateManager.hpp"
#include "../states/State.hpp"
#include "../audio/AudioManager.hpp"

#include <functional>
#include <string>
#include <map>
#include <memory>

enum MenuColors {notacolor, DEFAULT, SELECTED, PRESSED};
std::map<MenuColors, Color> menuColors;
void initMenuColors();
bool CompareColors(Color col1, Color col2);

class MenuButton : public GameObject {
private:
    std::string text;
    Color color;
    int fontSize;
    std::function<void()> click;
    std::shared_ptr<State> nextState;
public:
    MenuButton(Vector2 pos, Vector2 size, std::string text, int fontSize, std::function<void()> press) : GameObject(pos, {0,0}, size),
        text{text}, color{50, 50, 70, 255}, fontSize{fontSize}, click{press} {
        initMenuColors();
    };
    MenuButton(Vector2 pos, Vector2 size, std::string text, int fontSize, std::shared_ptr<State> nextState) : GameObject(pos, {0,0}, size),
        text{text}, color{50, 50, 70, 255}, fontSize{fontSize}, click{NULL}, nextState{nextState} {
        initMenuColors();
    };
    ~MenuButton() = default;

    void update() override {
        if (CompareColors(color, menuColors[PRESSED]) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            AudioManager::Get().playSound(_BUTTON);
            if (click != NULL) click();
            else {
                StateManager::Get().pushState(nextState);
            }
        }

        // project built without c++ wrapper, won't be adding operator overloading to Color
        if (cursorCollided()) {
            if (CompareColors(color, menuColors[DEFAULT]))
                color = menuColors[SELECTED];
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                color = menuColors[PRESSED];
            else color = menuColors[SELECTED];
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

    void setColor(Color col) {
        color = col;
    }

    bool cursorCollided() {
        return (GetMousePosition().x > position.x && GetMousePosition().y > position.y &&
            GetMousePosition().x < position.x + size.x && GetMousePosition().y < position.y + size.y);
    }
};

bool CompareColors(Color col1, Color col2) {
    return (col1.r == col2.r && col1.g == col2.g && col1.b == col2.b && col1.a == col2.a);
}

void initMenuColors() {
    menuColors[DEFAULT] = {50, 50, 70, 255};
    menuColors[SELECTED] = {100, 60, 70, 255};
    menuColors[PRESSED] = {70, 70, 70, 255};
}

#endif