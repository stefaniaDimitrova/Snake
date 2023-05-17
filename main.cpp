#include "board.hpp"
#include "gameobject.hpp"

int main()
{
    Board a(80,40);

    GameObject b (Point (1,1), Control('w','s','a','d'), 'o', a);
    GameObject c(Point(5,5), Control('o', 'l', 'k', ';'), '*', a);

    char input;
    std::cin >> input;
    while (input != 'q')
    {    
        if (input == 'w' || input == 'a' || input == 's' || input == 'd')
        {
            b.render(input);
        }
        else if (input == 'o' || input == 'k' || input == 'l' || input == ';')
        {
            c.render(input);
        }
        
        a.clear();
        a.setCell(b.getPosition(),b.getSymbol());
        a.setCell(c.getPosition(),c.getSymbol());
        system("cls");
        a.render();

        std::cin >> input;
    }
    
    return 0;
}