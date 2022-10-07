#ifndef _STATEMANAGER_HPP_
#define _STATEMANAGER_HPP_

#include "raylib.h"
#include <stack>
#include <map>
#include <memory>
#include <iostream>

#include "State.hpp"

enum StateNames {notastate, MENUSTATE, PLAYSTATE};
std::map<std::string, StateNames> stateNames;
void initStateNames();

class StateManager {
private:
    static StateManager instance;
    std::stack<std::shared_ptr<State>> states;
    StateManager() {
        initStateNames();
    }
public:
    static StateManager& Get() {
        return instance;
    }
    StateManager(const StateManager&) = delete;
    ~StateManager() = default;

    void pushState(std::shared_ptr<State> newState) {
        states.push(newState);
    }

    void popState() {
        states.pop();
    }

    void popStates(const unsigned int pops) {
        if (pops >= states.size()) {
            std::cout << pops << " cannot pop all/more than loaded states" << std::endl;
        }
        else {
            for(size_t i {0}; i < pops; i++)
                states.pop();
        }
    }

    void update() {
        states.top()->update();
    }

    void render() {
        states.top()->render();
    }
};

void initStateNames() {
    stateNames["menu"] = MENUSTATE;
    stateNames["play"] = PLAYSTATE;
}

StateManager StateManager::instance;

#endif