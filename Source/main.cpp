#define DOCTEST_CONFIG_IMPLEMENT
#include "../Headers/engine.hpp"
#include "Windows.h"
#include "iomanip"
#include "../Headers/doctest.h"
#include "../Headers/board.hpp"

TEST_CASE("Board Tests")
{
    Board board;

    //checks the constructor
    SUBCASE("Initial board state") 
    {
        CHECK(board.getWidth() == 0);
        CHECK(board.getHeight() == 0);
    }

    // Test case for setting and getting cell values
    SUBCASE("Set and Get Cell")
    {
        Board board;
        board.setWidth(10);
        board.setHeight(10);
        Point position(2, 3);
        char symbol = '#';

        board.setCell(position, symbol);
        CHECK(board.getCell(position) == symbol);
    }

    // Test case for checking if a position is within the board boundaries
    SUBCASE("Not Border")
    {
        Board board;
        board.setWidth(5);
        board.setHeight(5);

        CHECK(board.notBorder(Point(3, 3)) == true);  // Inside the board boundaries
        CHECK(board.notBorder(Point(0, 0)) == false);  // On the border
        CHECK(board.notBorder(Point(5, 5)) == false); // Outside the board boundaries
    }

     SUBCASE("Generating grid") {
        board.setWidth(10);
        board.setHeight(8);
        board.generateGrid();

        CHECK(board.getCell({0, 0}) == '|');
        CHECK(board.getCell({0, 9}) == '|');
        CHECK(board.getCell({7, 0}) == '|');
        CHECK(board.getCell({7, 9}) == '|');
        CHECK(board.getCell({0, 1}) == '_');
        CHECK(board.getCell({0, 8}) == '_');
        CHECK(board.getCell({7, 1}) == '-');
        CHECK(board.getCell({7, 8}) == '-');
        CHECK(board.getCell({1, 1}) == ' ');
        CHECK(board.getCell({6, 8}) == ' ');
    }

}

TEST_CASE("Control Tests")
{
    // Test case for getting control keys
    SUBCASE("Get Control Keys")
    {
        Control control('W', 'S', 'A', 'D');

        CHECK(control.getUp() == 'W');
        CHECK(control.getDown() == 'S');
        CHECK(control.getLeft() == 'A');
        CHECK(control.getRight() == 'D');
    }
}

TEST_CASE("GameObject") 
{
    Board board;
    GameObject object;

    SUBCASE("Default constructor") 
    {
        CHECK(object.getPosition() == Point(1, 1));
        CHECK(object.getSymbol() == ' ');
    }

    SUBCASE("Parametric constructor") 
    {
        GameObject object('X', board);

        CHECK(object.getSymbol() == 'X');
        CHECK(object.getPosition() == Point(1, 1));
    }

    SUBCASE("Setting position") 
    {
        object.setPosition(Point(5, 3));

        CHECK(object.getPosition() == Point(5, 3));
    }

    SUBCASE("Setting symbol") 
    {
        object.setSymbol('*');

        CHECK(object.getSymbol() == '*');
    }

    SUBCASE("Spawning the object") 
    {
        object.spawn(board);

        CHECK(object.getPosition().x >= 2);
        CHECK(object.getPosition().x < board.getWidth() - 1);
        CHECK(object.getPosition().y >= 2);
        CHECK(object.getPosition().y < board.getHeight() - 1);
    }

    SUBCASE("Rendering the object on the board") 
    {
        object.setPosition(Point(5, 3));
        object.setSymbol('*');
        object.render(board);

        CHECK(board.getCell(Point(5, 3)) == '*');
    }

    SUBCASE("Default collision behavior") 
    {
        object.setPosition(Point(5, 3));
        board.setCell(Point(5, 3), 'X');
        object.onCollision(board);

        CHECK(board.getCell(Point(5, 3)) == ' ');
        CHECK(board.getCell(Point(4, 3)) == '|');
        CHECK(board.getCell(Point(6, 3)) == '|');
    }
}

TEST_CASE("Snake class tests") 
{
    Board board;
    board.setHeight(10);
    board.setWidth(10);
    Direction direction = Direction::RIGHT;
    Control control;

    Snake snake('S', board, direction, control);

    SUBCASE("Default constructor") 
    {
        CHECK(snake.getLength() == 1);
        CHECK(snake.getSpeed() == 1);
        CHECK(snake.getAssisted() == false);
    }

    SUBCASE("Parametric constructor") 
    {
        CHECK(snake.getLength() == 1);
        CHECK(snake.getSpeed() == 1);
        CHECK(snake.getAssisted() == false);
        CHECK(snake.getHead() == Point(0, 0));
    }

    SUBCASE("Setter and getter for speed") 
    {
        snake.setSpeed(2);
        CHECK(snake.getSpeed() == 2);
    }

    SUBCASE("Setter and getter for objective") 
    {
        snake.setObjective(Point(5, 5));
        CHECK(snake.getHead() == Point(0, 0));
    }

    SUBCASE("Setter and getter for assisted") 
    {
        snake.setAssisted(true);
        CHECK(snake.getAssisted() == true);
    }

    SUBCASE("Move head") 
    {
        GameObject head('H', board);
        snake.moveHead(head);
        CHECK(head.getPosition() == Point(1, 0));
    }

    SUBCASE("Get next position") 
    {
        Point currentPosition(2, 2);
        Point nextPosition = snake.getNextPosition(currentPosition, Direction::UP);
        CHECK(nextPosition == Point(2, 1));
    }

    SUBCASE("Check collision") 
    {
        board.setCell(Point(1, 0), '|');
        GameObject head('H', board);
        bool collision = snake.checkCollision(head, board);
        CHECK(collision == true);
    }

    SUBCASE("On collision")
    {
        board.setCell(Point(1, 0), '+');
        snake.onCollision(board);
        CHECK(snake.getLength() == 2);
    }
}

TEST_CASE("Point Equality")
{
    SUBCASE("Points with same coordinates are equal")
    {
        Point p1(1, 2);
        Point p2(1, 2);

        CHECK(p1 == p2);
        CHECK(p2 == p1);
    }

    SUBCASE("Points with different coordinates are not equal")
    {
        Point p1(1, 2);
        Point p2(3, 4);

        CHECK_FALSE(p1 == p2);
        CHECK_FALSE(p2 == p1);
    }

    SUBCASE("Points with different coordinates are not equal")
    {
        Point p1(1, 2);
        Point p2(3, 4);

        CHECK(p1 != p2);
        CHECK(p2 != p1);
    }

    SUBCASE("Points with same coordinates are not equal")
    {
        Point p1(1, 2);
        Point p2(1, 2);

        CHECK_FALSE(p1 != p2);
        CHECK_FALSE(p2 != p1);
    }
}

TEST_CASE("Food Collision")
{
    Board board;
    board.setHeight(10);
    board.setWidth(10);

    SUBCASE("Food collides with an empty cell")
    {
        Food food('+', board);
        Point foodPosition(5, 5);
        board.setCell(foodPosition, '+');

        food.onCollision(board);

        CHECK(board.getCell(foodPosition) == ' ');
        CHECK(food.getCount() == 0);
    }

    SUBCASE("Food collides with a non-empty cell")
    {
        Food food('+', board);
        Point foodPosition(5, 5);
        board.setCell(foodPosition, 'A');

        food.onCollision(board);

        CHECK(board.getCell(foodPosition) == 'A');
        CHECK(food.getCount() == 1);
    }
}

TEST_CASE("Food Update")
{
    Board board;
    board.setHeight(10);
    board.setWidth(10);

    SUBCASE("Food count is less than 1")
    {
        Food food('+', board);
        Point foodPosition(5, 5);
        board.setCell(foodPosition, '+');
        food.setCount(0);

        food.update(board);

        CHECK(board.getCell(foodPosition) == '+');
        CHECK(food.getCount() == 1);
    }
SUBCASE("Food count is greater than or equal to 1")
    {
        Food food('+', board);
        Point foodPosition(5, 5);
        board.setCell(foodPosition, '+');
        food.setCount(2);

        food.update(board);

        CHECK(board.getCell(foodPosition) == '+');
        CHECK(food.getCount() == 2);
    }

    SUBCASE("Food count is equal to 1 and food spawns")
    {
        Food food('+', board);
        Point foodPosition(5, 5);
        board.setCell(foodPosition, ' ');
        food.setCount(1);

        food.update(board);

        CHECK(board.getCell(foodPosition) == '+');
        CHECK(food.getCount() == 2);
    }
}

TEST_CASE("Game Initialization")
{
    SUBCASE("Default Initialization")
    {
        Game game;

        CHECK(game.getPlayers().size() == 2);
        CHECK(game.gameOver() == false);
    }

    SUBCASE("Custom Initialization")
    {
        Game game;
        game.setPlayers(1);
        game.setSpeed(2);
        game.setAssisted(true);

        CHECK(game.getPlayers().size() == 1);
        CHECK(game.gameOver() == false);
    }
}

TEST_CASE("Game Over")
{
    SUBCASE("All Snakes Length <= 0")
    {
        Game game;
        game.setPlayers(2);
        game.getPlayers()[0].setLength(0);
        game.getPlayers()[1].setLength(0);

        CHECK(game.gameOver() == true);
    }

    SUBCASE("Two Snakes Collide")
    {
        Game game;
        game.setPlayers(2);
        game.getPlayers()[0].setPosition(Point(5, 5));
        game.getPlayers()[1].setPosition(Point(5, 5));

        CHECK(game.gameOver() == true);
    }
    SUBCASE("No Game Over Condition")
    {
        Game game;
        game.setPlayers(2);

        CHECK(game.gameOver() == false);
    }
}

int main()
{

    // doctest::Context().run();
    Engine engine;
    engine.start();

    return 0;
}