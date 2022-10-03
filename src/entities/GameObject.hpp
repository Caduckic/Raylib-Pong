#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_
#include "../config.hpp"
#include "raylib.h"

class GameObject {
protected:
    Vector2 position;
    Vector2 velocity;

public:
    GameObject(Vector2 pos, Vector2 vel) : position{pos}, velocity{vel} {};
    ~GameObject() = default;

    Vector2 getPosition() {
        return position;
    }
    Vector2 getVelocity() {
        return velocity;
    }

    void setPosition(Vector2 pos) {
        position = pos;
    }
    void setVelocity(Vector2 vel) {
        velocity = vel;
    }

    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif