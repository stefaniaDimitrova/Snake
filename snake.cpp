#include "snake.hpp"
#include <stdlib.h>
#include <list>

Snake::Snake()
{
    this->length = 1;
    this->body.reserve(length);
    this->symbol = ' ';
}

Snake::Snake(char symbol, Board &board, Direction direction,Control ctrl) : GameObject(symbol,board), currentDirection(direction),ctrl(ctrl)
{
    this->length = 1;
    for (size_t i = 0; i < this->length; i++)
    {
        this->body.push_back(GameObject(symbol,board));
    } 
    this->body.front().spawn(board);

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

bool Snake::getAte() const
{
    return this->ate;
}

void Snake::setSpeed(int speed)
{
    this->speed = speed;
}

bool Snake::getHit()
{
    return this->hit;
}

void Snake::assistedMove(Board& board) 
{
    this->shortest_path = bfs(board, this->body.front().getPosition(), objective);  

    if (!this->shortest_path.empty()) 
    {
        Point nextPosition = this->shortest_path[this->position];
        Point currentHeadPosition = this->body.front().getPosition();

        if (nextPosition != currentHeadPosition)
        {
            // Determine the direction to move based on the difference between the current head position and the next position
            if (nextPosition.y < currentHeadPosition.y && currentDirection != Direction::DOWN)
                this->changeDirection(this->ctrl.getUp());
            else if (nextPosition.y > currentHeadPosition.y && currentDirection != Direction::UP)
                this->changeDirection(this->ctrl.getDown());
            else if (nextPosition.x < currentHeadPosition.x && currentDirection != Direction::RIGHT)
                this->changeDirection(this->ctrl.getLeft());
            else if (nextPosition.x > currentHeadPosition.x && currentDirection != Direction::LEFT)
                this->changeDirection(this->ctrl.getRight());
        }

        this->body.front().setPosition(nextPosition);
        this->position++;

        if (this->position >= this->shortest_path.size())
            this->position = 0;
    }

    // Check if there are no valid moves available
    if (this->shortest_path.empty() || this->position >= this->shortest_path.size()) 
    {
        // Add logic to handle when there are no valid moves, e.g., choose a different objective or change the behavior of the assisted player.
        // For example, you can randomly choose a new objective or stop the snake's movement.
        // Alternatively, you can modify the bfs algorithm to handle cases where there are no valid moves.
        return; // Skip the collision check and body movement if there are no valid moves
    }
    
    Point head = this->body.front().getPosition();
    this->onCollision(board);
    this->MoveBody(head);
}



void Snake::MoveBody(Point head)
{
    if (this->assisted == false)
    {
    moveHead(this->body.front());
    }
    
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
        for(size_t i = 0; i <= this->speed; ++i)
        {
        this->changeDirection(input);
        this->onCollision(board);
        Point head = this->body.front().getPosition();
        this->MoveBody(head);
        }
}

void Snake::changeDirection(char input)
{
    if (input == ctrl.getDown())
    {        
        if (this->currentDirection == Direction::UP && this->collided == false)
        {
            return;
        }
        
        this->currentDirection = Direction::DOWN;
    }

    if (input == ctrl.getUp())
    {
         if (this->currentDirection == Direction::DOWN && this->collided == false)
        {
            return;
        }
        this->currentDirection = Direction::UP;
    }

    if (input == ctrl.getLeft())
    {
         if (this->currentDirection == Direction::RIGHT && this->collided == false)
        {
            return;
        }
        this->currentDirection = Direction::LEFT;
    }

    if (input == ctrl.getRight())
    {
         if (this->currentDirection == Direction::LEFT && this->collided == false)
        {
            return;
        }
        this->currentDirection = Direction::RIGHT;
    }   
}

bool Snake::getAssisted() const
{
    return this->assisted;
}

void Snake::setObjective(Point obj)
{
    this->objective = obj;
}

void Snake::setAssisted(bool a)
{
    this->assisted = a;
}

bool Snake::isValidPosition(Point position, Board &board)
{
    return board.notBorder(position);
}

std::vector<Point> Snake::bfs(Board& board, Point start, Point food) {
    std::vector<std::vector<bool>> visited(board.getHeight(), std::vector<bool>(board.getWidth(), false));
    std::vector<std::vector<Point>> previous(board.getHeight(), std::vector<Point>(board.getWidth()));
    std::list<Point> nodesToVisit;

    nodesToVisit.push_back(start);
    visited[start.y][start.x] = true;

    while (!nodesToVisit.empty()) {
        Point current = nodesToVisit.front();
        nodesToVisit.pop_front();

        if (current == food) {
            // Reconstruct the shortest path
            std::vector<Point> shortestPath;
            while (current != start) {
                shortestPath.push_back(current);
                current = previous[current.y][current.x];
            }
            shortestPath.push_back(start);
            std::reverse(shortestPath.begin(), shortestPath.end());
            return shortestPath;
        }

        for (int i = 0; i < 4; i++) {
            Direction d;
            switch (i) {
                case 0:
                    d = Direction::UP;
                    break;
                case 1:
                    d = Direction::DOWN;
                    break;
                case 2:
                    d = Direction::LEFT;
                    break;
                case 3:
                    d = Direction::RIGHT;
                    break;
                default:
                    break;
            }

            Point n = getNextPosition(current, d);
            if (isValidPosition(n, board) && !visited[n.y][n.x]) {
                visited[n.y][n.x] = true;
                nodesToVisit.push_back(n);
                previous[n.y][n.x] = current;
            }
        }
    }

    // No path found, return an empty vector
    return std::vector<Point>();
}

void Snake::render(Board &board)
{    
    for (size_t i = 0; i < this->body.size(); i++)
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

    // if (a == this->symbol)
    // {
    //     return true;
    // }
    
    
    return false;
}

#include <fstream>

void Snake::onCollision(Board &board)
{
    // this->render(board);
    this->ate = false;
    this->collided = false;
    if (checkCollision(this->body.front(), board))
    {
        Point next = getNextPosition(this->body.front().getPosition(),currentDirection);
        switch (board.getCell(next))
        {
        case '|':
            this->collided = true;
            this->changeDirection(this->ctrl.getDown());
            if (checkCollision(this->body.front(),board))
            {
                this->changeDirection(this->ctrl.getUp());
            }
            break;  
        case '_':
            this->collided = true;
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
            this->ate = true;
            this->body.push_back(GameObject(this->symbol,board));
            this->length++;
            break;
        case '~':
            // std::ofstream ofs("log.txt", std::ios::app);
            // ofs << "Snake position: " << this -> position.x << ' ' << this -> position.y << '\n';
            // ofs.close();
            this->body.pop_back();
            this->length--;
            break;
        }
    }
}