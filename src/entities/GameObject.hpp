#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_
#include "../config.hpp"
#include "raylib.h"

class GameObject {
protected:
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
public:
    GameObject(Vector2 pos, Vector2 vel, Vector2 size) : position{pos}, velocity{vel}, size{size} {};
    ~GameObject() = default;

    Vector2 getPosition() const {
        return position;
    }
    Vector2 getVelocity() const {
        return velocity;
    }

    Vector2 getSize() const {
        return size;
    }

    void setPosition(const Vector2& pos) {
        position = pos;
    }
    void setVelocity(const Vector2& vel) {
        velocity = vel;
    }

    void setSize(const Vector2& s) {
        size = s;
    }

    bool collided(GameObject& other) {
        return (position.x + size.x > other.getPosition().x &&
            position.x < other.getPosition().x + other.getSize().x &&
            position.y > other.getPosition().y - size.y &&
            position.y < other.getPosition().y + other.getSize().y);
    }

    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif