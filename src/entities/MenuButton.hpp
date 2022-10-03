#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include "GameObject.hpp"
#include "../states/StateManager.hpp"
#include <string>

//auto& state = StateManager::Get();

class MenuButton : public GameObject {
private:
    std::string text;
    Color color;
    
    Vector2 size;
public:
    MenuButton(Vector2 pos, std::string text) : GameObject(pos, {0,0}), text{text}, color{50, 50, 70, 255},
        size{400, 150} {};
    ~MenuButton() = default;

    void update() override {
        if (IsKeyPressed(KEY_F)) {
            //state.pushPlayState();
        }
    }

    virtual void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, color);

        DrawText(text.c_str(), position.x + (size.x / 2) - MeasureText(text.c_str(), MEDIUM_FONT_SIZE) / 2 + MEDIUM_FONT_SHADOW,
            position.y + (size.y / 2) - (MEDIUM_FONT_SIZE / 2) + MEDIUM_FONT_SHADOW, MEDIUM_FONT_SIZE, {0,0,0,60});
        DrawText(text.c_str(), position.x + (size.x / 2) - MeasureText(text.c_str(), MEDIUM_FONT_SIZE) / 2,
            position.y + (size.y / 2) - (MEDIUM_FONT_SIZE / 2), MEDIUM_FONT_SIZE, RAYWHITE);
    }

    void setColor(Color col) {
        color = col;
    }
};

#endif