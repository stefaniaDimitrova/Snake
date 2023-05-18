#include "snake.hpp"

Snake::Snake(Point start, char symbol, Board &board, Direction direction,Control ctrl) : GameObject(start,symbol,board), currentDirection(direction),ctrl(ctrl)
{
    this->length = 6;
    for (size_t i = 0; i < this->length; i++)
    {
        this->body.push_back(GameObject(Point(start.x -i,start.y),symbol,board));
    } 
}

void Snake::moveHead(GameObject &bodyPart)
{  
    if (this->currentDirection == Direction::DOWN)
    {
       bodyPart.setPosition(Point(this->position.x, this->position.y++));
    }
    else if (this->currentDirection == Direction::UP)
    {
        bodyPart.setPosition(Point(this->position.x, this->position.y--));
    }
    else if (this->currentDirection == Direction::RIGHT)
    {
        bodyPart.setPosition(Point(this->position.x++, this->position.y));
    }
    else if (this->currentDirection == Direction::LEFT)
    {
        bodyPart.setPosition(Point(this->position.x--, this->position.y));
    } 
}

void Snake::MoveBody(Point head)
{
    moveHead(this->body.front());
    Point next = head;
    Point last;
    for (size_t i = 1; i < this->length; i++)
    {

        last = this->body[i].getPosition();
        this->body[i].setPosition(next);
        next = last;
    }
    
}

void Snake::update(char input)
{
    Point head = this->body.front().getPosition();
    this->changeDirection(input);
    MoveBody(head);
}

void Snake::changeDirection(char input)
{
    if (input == ctrl.getDown())
    {
        this->currentDirection = Direction::DOWN;
    }

    if (input == ctrl.getUp())
    {
        this->currentDirection = Direction::UP;
    }

    if (input == ctrl.getLeft())
    {
        this->currentDirection = Direction::LEFT;
    }

    if (input == ctrl.getRight())
    {
        this->currentDirection = Direction::RIGHT;
    }   
}

void Snake::grow()
{

}

void Snake::render(Board &board)
{    
    for (size_t i = 0; i < this->length; i++)
    {
        board.setCell(this->body[i].getPosition(), this->body[i].getSymbol());
    }
    system("cls");
}

bool Snake::checkCollision()
{
    return false;
}