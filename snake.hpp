#pragma once
#include "gameobject.hpp"
#include "vector"
#include "direction.hpp"

class Snake : public GameObject
{
    protected:
    int length;
    std::vector <GameObject> body;
    Direction currentDirection;
    Control ctrl;
    
    public:
    Snake(Point start, char symbol, Board &board, Direction direction,Control ctrl);

    void moveHead(GameObject &bodyPart);
    void MoveBody(Point last);
    void changeDirection(char input);
    void grow();
    virtual void update(char input) override;
    bool checkCollision();
    virtual void render(Board &board) override;
    virtual ~Snake() = default;    
};