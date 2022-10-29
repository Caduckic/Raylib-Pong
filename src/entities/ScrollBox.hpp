#ifndef _SCROLLBOX_HPP_
#define _SCROLLBOX_HPP_

#include <vector>
#include <memory>
#include <string>
#include "UIElement.hpp"

class ScrollBox : public UIElement {
private:
    std::vector<std::shared_ptr<UIElement>> scrollList;
    int totalVisibleUI;
    float scrollBarPos;
    float UIHeight;
    float scrollValue;
    Vector2 scrollBarSize;
    bool barSelected;
    float barSelectedPos;
    float bottomElement;
public:
    ScrollBox(Vector2 pos, Vector2 size, std::string text, int fontSize, int totalVisibleUI,
        std::vector<std::shared_ptr<UIElement>> scrollList) : 
            UIElement(pos, size, text, fontSize), scrollList{scrollList}, totalVisibleUI{totalVisibleUI}, scrollBarPos{position.y},
            UIHeight{size.y / totalVisibleUI}, scrollValue{0}, scrollBarSize{30, 80}, barSelected{false}, barSelectedPos{0},
            bottomElement{position.y + (UIHeight * scrollList.size())} {};
    ~ScrollBox() = default;

    void initScrollList() {
        for (size_t i {0}; i < scrollList.size(); i++) {
            scrollList.at(i)->setSize({size.x - scrollBarSize.x, UIHeight});
            scrollList.at(i)->setPosition({position.x, position.y + (UIHeight * i)});
        }
    }

    void loadNext(std::vector<std::shared_ptr<UIElement>> nextElements) {
        for (auto& element : nextElements) {
            scrollList.push_back(element);
        }
    }

    bool cursorCollidedWithBar() {
        return (GetMousePosition().x > position.x + size.x - scrollBarSize.x && GetMousePosition().y > scrollBarPos &&
            GetMousePosition().x < position.x + size.x && GetMousePosition().y < scrollBarPos + scrollBarSize.y);
    }

    void update() override {
        scrollValue = (scrollBarPos - position.y)/((position.y + size.y - scrollBarSize.y) - position.y);

        if (cursorCollidedWithBar() && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !barSelected) {
            barSelected = true;
            barSelectedPos = GetMousePosition().y;
        }
        else if (barSelected && !IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            barSelected = false;
        }
        else if (barSelected && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && scrollBarPos <= position.y + size.y - scrollBarSize.y && scrollBarPos >= position.y) {
            scrollBarPos = GetMousePosition().y - scrollBarSize.y/2;
            if (scrollBarPos < position.y) scrollBarPos = position.y;
            else if (scrollBarPos > position.y + size.y - scrollBarSize.y) scrollBarPos = position.y + size.y - scrollBarSize.y;
        }

        for (auto& element : scrollList) {
            element->setPosition({element->getPosition().x, })
        }
    }

    void draw() override {
        DrawRectangle(position.x, position.y, size.x, size.y, GREEN);
        DrawText((std::to_string(scrollValue) + " " + std::to_string(scrollBarPos)).c_str(), 500, 300, SMALL_FONT_SIZE, RED);
        DrawRectangle(position.x + size.x - scrollBarSize.x, scrollBarPos, scrollBarSize.x, scrollBarSize.y, RED);

        for (auto& element : scrollList) {
            element->draw();
        }
    }
};

#endif