//the apple that the snake eats
#pragma once
#include "gameobject.hpp"

class Food : public GameObject
{
    public:
    void onCollision(GameObject &other) override;

    virtual ~Food() = default;
};