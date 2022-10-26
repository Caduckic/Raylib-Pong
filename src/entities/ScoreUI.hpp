#ifndef _SCOREUI_HPP_
#define _SCOREUI_HPP_

#include <array>
#include "UIElement.hpp"
#include "../SavedScore.hpp"

class ScoreUI : public UIElement {
private:
public:
    ScoreUI(Vector2 pos, Vector2 size, SavedScore score, int fontSize) : 
        UIElement(pos, size , score.getText(), fontSize) {};
    ~ScoreUI() = default;

    ScoreUI& operator=(const ScoreUI& scoreUI) {
        if (this == &scoreUI)
            return *this;
        
        text = scoreUI.text;
        color = scoreUI.color;
        fontSize = scoreUI.fontSize;
        return *this;
    }

    void update() override {

    }

    void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, color);

        DrawText(text.c_str(), position.x + (size.x / 2) - MeasureText(text.c_str(), fontSize) / 2 + (fontSize / FONT_SHADOW_OFFSET),
            position.y + (size.y / 2) - (fontSize / 2) + (fontSize / FONT_SHADOW_OFFSET), fontSize, {0,0,0,60});
        DrawText(text.c_str(), position.x + (size.x / 2) - MeasureText(text.c_str(), fontSize) / 2,
            position.y + (size.y / 2) - (fontSize / 2), fontSize, RAYWHITE);
    }
};

#endif