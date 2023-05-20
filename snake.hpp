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
    Point getNextPosition(Point position, Direction direction);
    void grow();
    virtual void update(char input, Board &board) override;
    bool checkCollision(GameObject head, Board &board);
    virtual void onCollision(Board &board) override;
    virtual void render(Board &board) override;
    virtual ~Snake() = default;    
};