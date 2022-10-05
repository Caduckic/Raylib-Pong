#ifndef _MODESELECTSTATE_HPP_
#define _MODESELECTSTATE_HPP_

#include <vector>
#include <functional>

#include "../entities/MenuButton.hpp"

class ModeSelectState {
private:
    
public:
    ModeSelectState(std::function<void()> push);
    ~ModeSelectState();
};

#endif