#ifndef _DUMMYSTATE_HPP_
#define _DUMMYSTATE_HPP_

#include "State.hpp"

class DummyState : public State {
public:
    DummyState() = default;
    ~DummyState() = default;

    virtual void update() override {

    }
    virtual void render() override {
        
    }

    //virtual void enter() = 0;
    //virtual void exit() = 0;
};

#endif