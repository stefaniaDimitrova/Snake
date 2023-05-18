#include "board.hpp"
#include "gameobject.hpp"
#include "Windows.h"

int main()
{
    Board a(80,40);

    GameObject player1 (Point (1,1), Control('w','s','a','d'), 'o', a);
    GameObject player2(Point(5,5), Control('o', 'l', 'k', ';'), '*', a);

    char input;
    input = _getch();
    while (input != 'q')
    {    
        if (input == 'w' || input == 'a' || input == 's' || input == 'd')
        {
            player1.update(input);
        }
        else if (input == 'o' || input == 'k' || input == 'l' || input == ';')
        {
            player2.update(input);
        }
        player1.render(a);
        player2.render(a);
        a.render();
        a.clear();

        input = _getch();
        SetCursor(NULL);
    }
    
    return 0;
}