#ifndef _UIELEMENTCONTAINER_HPP_
#define _UIELEMENTCONTAINER_HPP_

#include <vector>
#include <memory>
#include "UIElement.hpp"

class UIElementContainer : public UIElement {
private:
    std::vector<std::shared_ptr<UIElement>> elements;
public:
    UIElementContainer();
    ~UIElementContainer();

    void update() override {
        
    }

    void draw() override {

    }
};

#endif