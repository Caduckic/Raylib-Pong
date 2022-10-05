#ifndef _STATE_HPP_
#define _STATE_HPP_

class State {
public:
    State() = default;
    ~State() = default;

    virtual void init() {};
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif