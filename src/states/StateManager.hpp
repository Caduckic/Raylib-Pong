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
        /*try {
            bool failed {false};
            auto& s = states;
            switch (stateNames[stateName]) {
            case MENUSTATE:
                states.push(std::make_unique<MenuState>([&s](){s.push(std::make_unique<PlayState>([&s](){s.pop();}));}));
                break;
            case PLAYSTATE:
                states.push(std::make_unique<PlayState>([&s](){s.pop();}));
                break;
            default:
                failed = true;
                break;
            }
            if (failed) throw(stateName);
        } catch (std::string state) {
            std::cout << "\"" << state << "\" is not a valid state" << std::endl;
        }*/
    }

    void popState() {
        states.pop();
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