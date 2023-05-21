#include "board.hpp"
#include "snake.hpp"
#include "food.hpp"
#include "poison.hpp"
#include "Windows.h"
#include "iomanip"

int main()
{
    Board board(46,23);

    Snake player1('o', board, Direction::RIGHT, Control('w','s','a','d'));

    Food food ('+',board);
    Poison poison ('~' , board);

    char input;
    //have to hide the cursor
    std::cout <<"Press any key to start the game" << std::endl;
    input = _getch();
    std::cout << "Game has stearted!" << std::endl;
    while (input != 'q')
    {    
        while(!_kbhit())
        {
        food.render(board);
        poison.render(board);
        player1.update(input, board);
        player1.render(board);
        // player2.update(input);
        // player2.render(a);
        board.render();
        food.update(board);
        poison.update(board);
        board.clear();
        }
        input = _getch();
       
    }    
    return 0;
}