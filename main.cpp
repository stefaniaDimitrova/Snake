#include "board.hpp"
#include "snake.hpp"
#include "Windows.h"
#include "iomanip"

int main()
{
    Board board(46,23);

    Snake player1('o', board, Direction::RIGHT, Control('w','s','a','d'));


    char input;
    //have to hide the cursor
    std::cout <<"Press any key to start the game" << std::endl;
    input = _getch();
    std::cout << "Game has stearted!" << std::endl;
    int i = 0;
    while (input != 'q')
    {    
        while(!_kbhit())
        {
            //make them both move at the same time
        player1.update(input, board);
        player1.render(board);
        // player2.update(input);
        // player2.render(a);
        board.render();
        board.clear();
        }
        input = _getch();
    } 
    

    
    return 0;
}