#ifndef _UIELEMENT_HPP_
#define _UIELEMENT_HPP_

#include "GameObject.hpp"
#include <map>
#include <string>

enum MenuColors {notacolor, DEFAULT, SELECTED, PRESSED};
std::map<MenuColors, Color> menuColors;
void initMenuColors();
bool CompareColors(Color col1, Color col2);

class UIElement : public GameObject {
protected:
    std::string text;
    Color color;
    int fontSize;
public:
    UIElement(Vector2 pos, Vector2 size ,std::string text, int fontSize) : GameObject(pos, {0,0}, size),
        text{text}, color{50, 50, 70, 255}, fontSize{fontSize} {};
    ~UIElement() = default;

    virtual void update() = 0;
    virtual void draw() = 0;

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