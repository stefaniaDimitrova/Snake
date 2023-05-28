#pragma once
#include "gameobject.hpp"
#include <vector>
#include "direction.hpp"
#include <algorithm>

/*! Class Snake  */
class Snake : public GameObject
{
    /*! Variables for the snake
    * collided - checks if the player has collided with a wall
    * assisted - checks id the player is controlled by the computer
    * speed - keeps track of the speed
    * int position - keeps track of the index while moving around the shortest path 
    * objective - the position that the player controlled by the computer has to reach
    * length - keeps track of the player's body
    * shortest_path - holds the most efficient way for the player to reach its destination
    * body - a vector that keeps the snakes body
    * currentDirection - keeps track of the direction the player is moving
    * ctrl - the controls the player uses to move*/
    protected:
    bool collided = false;
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
    /*! Default constructor */
    Snake();

    /*! Paametric constructor */
    Snake(char symbol, Board &board, Direction direction,Control ctrl);

    /*! Getter for the length */
    const int getLength() const;

    /*! Getter for the speed */
    int getSpeed() const;

    /*! Getter for assisted */
    bool getAssisted() const;

    /*! Getter for the head */
    Point getHead() const;

    /*! Method that moves the first element of the body vector (the snake's head) */
    void moveHead(GameObject &bodyPart);

    /*! Moves the snakes body with one cell in the direction the head is moving 
    @param head is the next position the body has to have */
    void MoveBody(Point head);

    /*! Setter for the speed */
    void setSpeed(int speed);

    /*! Setter for length */
    void setLength(int length);

    /*! Setter for the objective */
    void setObjective(Point obj);

    /*! Setter for the assisted */
    void setAssisted(bool a);

    /*! Checks if a position is valid */
    bool isValidPosition(Point position, Board &board);

    /*!  Implementation of the BFS algorithm which calculates the shortest possible route for the snake to reach the food
    @return a vector of points that represent the players path to its destination*/
    std::vector<Point> bfs(Board& board, Point start, Point food);

    /*! Takes care of the player's movement id they are controlled by the computer */
    void assistedMove(Board &board);

    /*! Determine what key was pressed based on the movement's direction */
    char determineInput(Direction dir);

    /*! Method to change the player's movement */
    void changeDirection(char input);

    /*! Mthod to tell the player what he next position will be based on their current position and their direction */
    Point getNextPosition(Point position, Direction direction);

    /*! Method to update the player's condition */
    virtual void update(char input, Board &board);

    /*! Method to check if the player has collided */
    bool checkCollision(GameObject head, Board &board);

    /*! Method to set player's behaviour when they collide */
    virtual void onCollision(Board &board) override;

    /*! Method to put the player on the board */
    virtual void render(Board &board) override;
    
    /*! Default destructor */
    virtual ~Snake() = default;    
};