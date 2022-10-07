#ifndef _INPUTFIELD_HPP_
#define _INPUTFIELD_HPP_

#include "UIElement.hpp"
#include "math.h"

#include <iostream>

class InputField : public UIElement {
private:
    bool selected;
    bool blink;
    float blinkTimer;
public:
    InputField(Vector2 pos, Vector2 size, int fontSize) : UIElement(pos, size, "", fontSize),
        selected{false}, blink{false}, blinkTimer{0} {};
    ~InputField() = default;

    virtual void update() {
        if (CompareColors(color, menuColors[PRESSED]) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            selected = true;
        }
        if (!cursorCollided() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            selected = false;
        }

        if (cursorCollided()) {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            if (CompareColors(color, menuColors[DEFAULT]) && !selected)
                color = menuColors[SELECTED];
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                color = menuColors[PRESSED];
        }
        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            color = menuColors[DEFAULT];
        }

        if (selected) {
            blinkTimer += GetFrameTime();
            if (blinkTimer >= INPUT_BLINK_TIME) {
                blink = !blink;
                blinkTimer = fmod(blinkTimer, INPUT_BLINK_TIME);
            }
            int key = GetCharPressed();

            while (key > 0) {
                if (key >= 32 && key <= 125 && text.length() < MAX_NAME_CHARS) {
                    text += (char)key;
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE) && text.length() > 0) {
                text.pop_back();
            }
        }
    }

    virtual void draw() {
        DrawRectangle(position.x, position.y, size.x, size.y, color);

        DrawText((!blink || text.length() >= MAX_NAME_CHARS) ? text.c_str() : (text + "_").c_str(),
            position.x + (size.x / 2) - MeasureText(text.c_str(), fontSize) / 2 + (fontSize / FONT_SHADOW_OFFSET),
            position.y + (size.y / 2) - (fontSize / 2) + (fontSize / FONT_SHADOW_OFFSET), fontSize, {0,0,0,60});
        DrawText((!blink || text.length() >= MAX_NAME_CHARS) ? text.c_str() : (text + "_").c_str(),
            position.x + (size.x / 2) - MeasureText(text.c_str(), fontSize) / 2,
            position.y + (size.y / 2) - (fontSize / 2), fontSize, RAYWHITE);
    }

    std::string getText() const {
        return text;
    }
};

#endif