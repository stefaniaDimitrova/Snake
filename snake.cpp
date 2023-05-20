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
       bodyPart.setPosition(getNextPosition(bodyPart.getPosition(),currentDirection));
    }
    else if (this->currentDirection == Direction::UP)
    {
        bodyPart.setPosition(getNextPosition(bodyPart.getPosition(),currentDirection));
    }
    else if (this->currentDirection == Direction::RIGHT)
    {
        bodyPart.setPosition(getNextPosition(bodyPart.getPosition(),currentDirection));
    }
    else if (this->currentDirection == Direction::LEFT)
    {
        bodyPart.setPosition(getNextPosition(bodyPart.getPosition(),currentDirection));
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

void Snake::update(char input, Board &board)
{
    Point head = this->body.front().getPosition();
    this->changeDirection(input);
    this->onCollision(board);
    this->MoveBody(head);
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

Point Snake::getNextPosition(Point position, Direction direction)
{
    switch (direction)
    {
    case Direction::UP:
        position.y--;
        break;
    case Direction::DOWN:
        position.y++;
        break;
    case Direction::RIGHT:
        position.x++;
        break;
    case Direction::LEFT:
        position.x--;
        break;
    }

    return position;
}

bool Snake::checkCollision(GameObject head,Board &board)
{
    Point next = getNextPosition(head.getPosition(), currentDirection);
    char a = board.getCell(next);

    if (a != ' ')
    {
        return true;
    }
    
    return false;
}

void Snake::onCollision(Board &board)
{
    if (checkCollision(this->body.front(), board))
    {
        Point next = getNextPosition(this->body.front().getPosition(),currentDirection);
        switch (board.getCell(next))
        {
        case '|':
        changeDirection(this->ctrl.getDown());
        if(checkCollision(this->body.front(),board)) changeDirection(this->ctrl.getUp());  
        board.clear();        
        case '+':
            this->length++;
            break;
        case '~':
            this->length--;
            break;
        default:
            // throw "Game over!";
            break;
        }
    }
}