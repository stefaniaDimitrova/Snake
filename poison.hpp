#pragma once
#include "gameobject.hpp"

class Poison : public GameObject
{
    public:
    void onCollision(GameObject &other) override;

    virtual ~Poison() = default;
};