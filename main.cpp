#include "board.hpp"
#include "gameobject.hpp"

int main()
{
    Board a(80,40);

    GameObject b (Point (1,1), Control('w','s','a','d'), 'o', a);
    // GameObject c(Point(5,5), Control('o', 'l', 'k', ';'), '*', a);

    a.render();

    while (true)
    {    
        
        b.render();
        // c.render();
        a.clear();
        a.setCell(b.getPosition(),b.getSymbol());
        // a.setCell(c.getPosition(),c.getSymbol());
        a.render();
    }
    
    return 0;
}