#include "snake.hpp"

Snake::Snake(char symbol, Board &board, Direction direction,Control ctrl) : GameObject(symbol,board), currentDirection(direction),ctrl(ctrl)
{
    this->length = 1;
    for (size_t i = 0; i < this->length; i++)
    {
        this->body.push_back(GameObject(symbol,board));
    } 
    std::cout << "Snake" << std::endl;
    this->body.front().spawn(board);
    std::cout << "x: " << this->body.front().getPosition().x<< " y: " << this->body.front().getPosition().y<< std::endl; 

}

const int Snake::getLength() const
{
    return this->length;
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
    this->changeDirection(input);
    this->onCollision(board);
    Point head = this->body.front().getPosition();
    this->MoveBody(head);
}

void Snake::changeDirection(char input)
{
    if (input == ctrl.getDown())
    {
        // if (this->currentDirection == Direction::UP)
        // {
        //     return;
        // }
        
        this->currentDirection = Direction::DOWN;
    }

    if (input == ctrl.getUp())
    {
        //  if (this->currentDirection == Direction::DOWN)
        // {
        //     return;
        // }
        this->currentDirection = Direction::UP;
    }

    if (input == ctrl.getLeft())
    {
        //  if (this->currentDirection == Direction::RIGHT)
        // {
        //     return;
        // }
        this->currentDirection = Direction::LEFT;
    }

    if (input == ctrl.getRight())
    {
        //  if (this->currentDirection == Direction::LEFT)
        // {
        //     return;
        // }
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
            this->changeDirection(this->ctrl.getDown());
            if (checkCollision(this->body.front(),board))
            {
                this->changeDirection(this->ctrl.getUp());
            }
            break;  
        case '_':
            this->changeDirection(this->ctrl.getLeft());
            if (checkCollision(this->body.front(),board))
            {
                this->changeDirection(this->ctrl.getRight());
            }
            break;
        case '-':
            this->changeDirection(this->ctrl.getRight());
            if (checkCollision(this->body.front(), board))
            {
                this->changeDirection(this->ctrl.getLeft());
            }
            break;
        case '+':
            this->body.push_back(GameObject(this->symbol,board));
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