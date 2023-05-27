#include "engine.hpp"
#include "Windows.h"
#include "iomanip"

int main()
{

    // Engine engine;
    // engine.start();
    /*      things to fix:
    -the border bug 
    -moving in opposite directions ***
    -poison spawner ***
    -two players at the same time ***
    -collision with another player and with yourself
    -exceptions
    -tests
    -ui **
    -game class ***
    -levels
    */
    // Board board;
    // board.setHeight(23);
    // board.setWidth(46);
    // board.generateGrid();

    // Snake player1('o', board, Direction::RIGHT, Control('w','s','a','d'));
    // // Snake player2('*',board,Direction::LEFT,Control('i','k','j','l'));

    // Food food ('+',board);
    // Poison poison ('~' , board);

    // char input;
    // //have to hide the cursor
    // std::cout <<"Press any key to start the game" << std::endl;
    // input = _getch();
    // std::cout << "Game has stearted!" << std::endl;
    // while (input != 'q')
    // {   
    //     while(!_kbhit())
    //     {
    //     food.render(board);
    //     poison.render(board);
    //     player1.update(input, board);
    //     player1.render(board);
    //     // player2.update(input,board);
    //     // player2.render(board);
    //     board.render();
    //     food.update(board);
    //     poison.update(board);
    //     board.clear();
    //     }
    //     input = _getch();
    // }    

    // std::cout << std::boolalpha << player1.getGameOver();

    Game snake;
    snake.start();
}