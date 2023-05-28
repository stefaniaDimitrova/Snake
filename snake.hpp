#pragma once
#include "gameobject.hpp"
#include <vector>
#include "direction.hpp"
#include <algorithm>

class Snake : public GameObject
{
    protected:
    bool collided = false;
    bool hit = false;
    bool ate = true;
    bool assisted = false;
    int speed = 1;
    int position = 0;
    Point objective;
    int length;
    std::vector<Point> shortest_path;
    std::vector <GameObject> body;
    Direction currentDirection;
    Control ctrl;
    
    public:
    Snake();
    Snake(char symbol, Board &board, Direction direction,Control ctrl);
    const int getLength() const;
    void moveHead(GameObject &bodyPart);
    void MoveBody(Point last);
    void setSpeed(int speed);
    bool getAte() const;
    int getSpeed() const;
    bool getAssisted() const;
    void setObjective(Point obj);
    void setAssisted(bool a);
    bool isValidPosition(Point position, Board &board);
    std::vector<Point> bfs(Board& board, Point start, Point food);
    bool getHit();
    void assistedMove(Board &board);
    char determineInput(Direction dir);
    // void setDirection(Direction dir);
    // void setControls(Control ctrl);
    void changeDirection(char input);
    Point getNextPosition(Point position, Direction direction);
    virtual void update(char input, Board &board);
    bool checkCollision(GameObject head, Board &board);
    virtual void onCollision(Board &board) override;
    virtual void render(Board &board) override;
    virtual ~Snake() = default;    
};