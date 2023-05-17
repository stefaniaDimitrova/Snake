#pragma once
#include "gameobject.hpp"

class Poison : public GameObject
{
    public:
    void onCollision() override;
};