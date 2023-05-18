#include "board.hpp"
#include "gameobject.hpp"
#include "Windows.h"
#include "iomanip"

int main()
{
    Board a(80,40);

    GameObject player1 (Point (1,1), Control('w','s','a','d'), 'o', a);
    // GameObject player2(Point(5,5), Control('o', 'l', 'k', ';'), '*', a);

    char input;

    //have to hide the cursor
    std::cout <<"Press any key to start the game" << std::endl;
    input = _getch();
    std::cout << "Game has stearted!" << std::endl;
    while (input != 'q')
    {    
        while(!_kbhit())
        {
            //make them both move at the same time
        player1.update(input);
        // player2.update(input);
        player1.render(a);
        // player2.render(a);
        a.render();
        a.clear();
        }
        input = _getch();
    } 
    

    
    return 0;
}